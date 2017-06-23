//
//  NSObject+PQWXHook.m
//  PQWXHook
//
//  Created by Docee on 16/3/8.
//  Copyright © 2016年 tencent. All rights reserved.
//

#import "NSObject+PQWXHook.h"

static int const kCloseRedEnvPlugin = 0;
static int const kOpenRedEnvPlugin = 1;
static int const kCloseRedEnvPluginForMyself = 2;
static int const kCloseRedEnvPluginForMyselfFromChatroom = 3;

//0：关闭红包插件
//1：打开红包插件
//2: 不抢自己的红包
//3: 不抢群里自己发的红包
static int HBPliginType = 0;
static NSInteger timereceive = 300000;


@implementation NSObject (PQWXHook)




/**
 *  @brief AsyncOnAddMsg Hook方法
 *
 *  @param msg  联系人名称
 *  @param wrap 消息内容
 */
- (void)hook_AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap {
    
    
    NSLog(@"收到消息：%@ 内容：%@",msg,wrap.m_nsContent);
    
    [self orin_AsyncOnAddMsg:msg MsgWrap:wrap];

    
    
    switch(wrap.m_uiMessageType) {
        case 1:
        {
            //普通消息
            //红包插件功能
            //0：关闭红包插件
            //1：打开红包插件
            //2: 不抢自己的红包
            //3: 不抢群里自己发的红包
            //微信的服务中心
//            Method methodMMServiceCenter = class_getClassMethod(objc_getClass("MMServiceCenter"), @selector(defaultCenter));
//            IMP impMMSC = method_getImplementation(methodMMServiceCenter);
//            id MMServiceCenter = impMMSC(objc_getClass("MMServiceCenter"), @selector(defaultCenter));
////            //通讯录管理器
//            id contactManager = ((id (*)(id, SEL, Class))objc_msgSend)(MMServiceCenter, @selector(getService:),objc_getClass("CContactMgr"));
//            id selfContact = objc_msgSend(contactManager, @selector(getSelfContact));
//            
//            Ivar nsUsrNameIvar = class_getInstanceVariable([selfContact class], "m_nsUsrName");
//            id m_nsUsrName = object_getIvar(selfContact, nsUsrNameIvar);
            BOOL isMesasgeFromMe = NO;
            if ([wrap.m_nsFromUsr isEqualToString:wrap.m_nsToUsr]) {
                //发给自己的消息
                isMesasgeFromMe = YES;
            }
            
            if (isMesasgeFromMe)
            {
                if ([wrap.m_nsContent rangeOfString:@"打开红包插件"].location != NSNotFound)
                {
                    HBPliginType = kOpenRedEnvPlugin;
                }
                else if ([wrap.m_nsContent rangeOfString:@"关闭红包插件"].location != NSNotFound)
                {
                    HBPliginType = kCloseRedEnvPlugin;
                }
                else if ([wrap.m_nsContent rangeOfString:@"关闭抢自己红包"].location != NSNotFound)
                {
                    HBPliginType = kCloseRedEnvPluginForMyself;
                }
                else if ([wrap.m_nsContent rangeOfString:@"关闭抢自己群红包"].location != NSNotFound)
                {
                    HBPliginType = kCloseRedEnvPluginForMyselfFromChatroom;
                }
                else if ([wrap.m_nsContent rangeOfString:@"时间"].location != NSNotFound)
                {
                    NSArray *array = [wrap.m_nsContent componentsSeparatedByString:@"-"];
                    timereceive = [[NSString stringWithFormat:@"%@",array[1]] integerValue];
                }
                
            }
        }
            break;
        case 49: { // AppNode
            
            CContactMgr *contactManager = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("CContactMgr") class]];
            CContact *selfContact = [contactManager getSelfContact];
            
            BOOL isMesasgeFromMe = NO;
            if([wrap.m_nsFromUsr isEqualToString:selfContact.m_nsUsrName]) {
                
                isMesasgeFromMe = YES;
                
            }
            BOOL isChatroom = NO;
            if ([wrap.m_nsToUsr rangeOfString:@"@chatroom"].location != NSNotFound)
            {
                isChatroom = YES;
            }
            if (isMesasgeFromMe && kCloseRedEnvPluginForMyself == HBPliginType && !isChatroom) {
                //不抢自己的红包
                break;
            }
            else if(isMesasgeFromMe && kCloseRedEnvPluginForMyselfFromChatroom == HBPliginType && isChatroom)
            {
                //不抢群里自己的红包
                break;
            }
            
            
            if ([wrap.m_nsContent rangeOfString:@"wxpay://"].location != NSNotFound) { // 红包
//                if ([wrap.m_nsFromUsr rangeOfString:@"@chatroom"].location != NSNotFound ||
//                    (isMesasgeFromMe && [wrap.m_nsToUsr rangeOfString:@"@chatroom"].location != NSNotFound)) { // 群组红包或群组里自己发的红包
                usleep(timereceive);
                    NSString *nativeUrl = [[wrap m_oWCPayInfoItem] m_c2cNativeUrl];
                    nativeUrl = [nativeUrl substringFromIndex:[@"wxpay://c2cbizmessagehandler/hongbao/receivehongbao?" length]];
                    
                    NSDictionary *nativeUrlDict = [objc_getClass("WCBizUtil") dictionaryWithDecodedComponets:nativeUrl separator:@"&"];
                    
                    /** 构造参数 */
                    NSMutableDictionary *params = [@{} mutableCopy];
                    [params pq_setSafeObject:nativeUrlDict[@"msgtype"] forKey:@"msgType"];
                    [params pq_setSafeObject:nativeUrlDict[@"sendid"] forKey:@"sendId"];
                    [params pq_setSafeObject:nativeUrlDict[@"channelid"] forKey:@"channelId"];
                    [params pq_setSafeObject:[selfContact getContactDisplayName] forKey:@"nickName"];
                    [params pq_setSafeObject:[selfContact m_nsHeadImgUrl] forKey:@"headImg"];
                    [params pq_setSafeObject:[[wrap m_oWCPayInfoItem] m_c2cNativeUrl] forKey:@"nativeUrl"];
                    [params pq_setSafeObject:wrap.m_nsFromUsr forKey:@"sessionUserName"];
                    
                    WCRedEnvelopesLogicMgr *logicMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("WCRedEnvelopesLogicMgr") class]];
                if (kCloseRedEnvPlugin != HBPliginType) {
                 [logicMgr OpenRedEnvelopesRequest:params];
//                    [logicMgr QueryRedEnvelopesDetailRequest:params];
                }
//                }
            }
            break;
        };
        default:
            break;
    }
    
}

/**
 *  @brief AsyncOnAddMsg原方法，不需要实现
 *
 *  @param msg  联系人名称
 *  @param wrap 消息内容
 */
- (void)orin_AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap {}


@end

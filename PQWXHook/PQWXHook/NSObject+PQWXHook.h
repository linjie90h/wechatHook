//
//  NSObject+PQWXHook.h
//  PQWXHook
//
//  Created by Docee on 16/3/8.
//  Copyright © 2016年 tencent. All rights reserved.
//



#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "CMessageWrap+APP.h"
#import "CContactMgr.h"
#import "MMServiceCenter.h"
#import "CContact.h"
#import "NSMutableDictionary+Safe.h"
#import "WCBizUtil.h"
#import "WCRedEnvelopesLogicMgr.h"


#define PQHookInstanceMethod(classname, ori_sel, new_sel) \
\
{ \
Class class = objc_getClass(#classname); \
Method ori_method = class_getInstanceMethod(class, ori_sel); \
Method new_method = class_getInstanceMethod(class, new_sel); \
method_exchangeImplementations(ori_method, new_method); \
} \
\

@interface NSObject (PQWXHook)


- (void)hook_AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap;
- (void)orin_AsyncOnAddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap;


@end


static void __attribute__((constructor)) initialize(void) {
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored"-Wundeclared-selector"
    
    PQHookInstanceMethod(CMessageMgr, @selector(orin_AsyncOnAddMsg:MsgWrap:), @selector(AsyncOnAddMsg:MsgWrap:));
    PQHookInstanceMethod(CMessageMgr, @selector(AsyncOnAddMsg:MsgWrap:), @selector(hook_AsyncOnAddMsg:MsgWrap:));
    
#pragma clang diagnostic pop

}



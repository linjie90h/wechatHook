//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CMessageWrap.h"
#import "WCPayInfoItem.h"

@interface CMessageWrap (APP)
+ (void)GetPathOfAppData:(id)arg1 LocalID:(unsigned int)arg2 FileExt:(id)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppDataByUserName:(id)arg1 andMessageWrap:(id)arg2 andAttachId:(id)arg3 andAttachFileExt:(id)arg4 retStrPath:(id *)arg5;
+ (void)GetPathOfAppDataByUserName:(id)arg1 andMessageWrap:(id)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDataTemp:(id)arg1 LocalID:(unsigned int)arg2 AttachId:(id)arg3 retStrPath:(id *)arg4;
+ (void)GetPathOfAppDataTemp:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfAppDir:(id)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppImgCacheDir:(id)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppRemindAttach:(id)arg1 retStrPath:(id *)arg2;
+ (void)GetPathOfAppThumb:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
+ (void)GetPathOfMaskedAppThumb:(id)arg1 LocalID:(unsigned int)arg2 retStrPath:(id *)arg3;
- (id)nativeUrl;
- (id)wishingString;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(retain, nonatomic) NSArray *m_arrCustomWrap; // @dynamic m_arrCustomWrap;
@property(nonatomic) _Bool m_bIsForceUpdate; // @dynamic m_bIsForceUpdate;
@property(readonly, nonatomic) _Bool m_isContentOriginal; // @dynamic m_isContentOriginal;
@property(nonatomic) _Bool m_isDirectSend; // @dynamic m_isDirectSend;
@property(retain, nonatomic) NSString *m_nsAppAction; // @dynamic m_nsAppAction;
@property(retain, nonatomic) NSString *m_nsAppContent; // @dynamic m_nsAppContent;
@property(retain, nonatomic) NSString *m_nsAppExtInfo; // @dynamic m_nsAppExtInfo;
@property(retain, nonatomic) NSString *m_nsAppMediaDataUrl; // @dynamic m_nsAppMediaDataUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaLowBandDataUrl; // @dynamic m_nsAppMediaLowBandDataUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaLowUrl; // @dynamic m_nsAppMediaLowUrl;
@property(retain, nonatomic) NSString *m_nsAppMediaTagName; // @dynamic m_nsAppMediaTagName;
@property(retain, nonatomic) NSString *m_nsAppMediaUrl; // @dynamic m_nsAppMediaUrl;
@property(retain, nonatomic) NSString *m_nsAppMessageAction; // @dynamic m_nsAppMessageAction;
@property(retain, nonatomic) NSString *m_nsAppMessageExt; // @dynamic m_nsAppMessageExt;
@property(retain, nonatomic) NSString *m_nsAppName; // @dynamic m_nsAppName;
@property(retain, nonatomic) NSString *m_nsDesc; // @dynamic m_nsDesc;
@property(retain, nonatomic) NSString *m_nsRemindAttachId; // @dynamic m_nsRemindAttachId;
@property(retain, nonatomic) NSString *m_nsSourceDisplayname; // @dynamic m_nsSourceDisplayname;
@property(retain, nonatomic) NSString *m_nsSourceUsername; // @dynamic m_nsSourceUsername;
@property(retain, nonatomic) NSString *m_nsStreamVideoAdUxInfo; // @dynamic m_nsStreamVideoAdUxInfo;
@property(retain, nonatomic) NSString *m_nsStreamVideoPublishId; // @dynamic m_nsStreamVideoPublishId;
@property(retain, nonatomic) NSString *m_nsStreamVideoThumbUrl; // @dynamic m_nsStreamVideoThumbUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoTitle; // @dynamic m_nsStreamVideoTitle;
@property(retain, nonatomic) NSString *m_nsStreamVideoUrl; // @dynamic m_nsStreamVideoUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoWebUrl; // @dynamic m_nsStreamVideoWebUrl;
@property(retain, nonatomic) NSString *m_nsStreamVideoWording; // @dynamic m_nsStreamVideoWording;
@property(retain, nonatomic) NSString *m_nsTemplateId; // @dynamic m_nsTemplateId;
@property(retain, nonatomic) NSString *m_nsThumbUrl; // @dynamic m_nsThumbUrl;
@property(retain, nonatomic) NSString *m_nsTitle; // @dynamic m_nsTitle;
@property(retain, nonatomic) WCPayInfoItem *m_oWCPayInfoItem; // @dynamic m_oWCPayInfoItem;
@property(nonatomic) unsigned int m_uiAppContentAttributeBitSetFlag; // @dynamic m_uiAppContentAttributeBitSetFlag;
@property(nonatomic) unsigned int m_uiAppExtShowType; // @dynamic m_uiAppExtShowType;
@property(nonatomic) unsigned int m_uiAppVersion; // @dynamic m_uiAppVersion;
@property(nonatomic) unsigned int m_uiEncryVer; // @dynamic m_uiEncryVer;
@property(nonatomic) unsigned int m_uiOriginFormat; // @dynamic m_uiOriginFormat;
@property(nonatomic) unsigned int m_uiOriginMsgSvrId; // @dynamic m_uiOriginMsgSvrId;
@property(nonatomic) unsigned int m_uiRemindAttachTotalLen; // @dynamic m_uiRemindAttachTotalLen;
@property(nonatomic) unsigned int m_uiRemindFormat; // @dynamic m_uiRemindFormat;
@property(nonatomic) unsigned int m_uiRemindId; // @dynamic m_uiRemindId;
@property(nonatomic) unsigned int m_uiRemindTime; // @dynamic m_uiRemindTime;
@property(nonatomic) unsigned int m_uiShowType; // @dynamic m_uiShowType;
@property(nonatomic) unsigned int m_uiStreamVideoTime; // @dynamic m_uiStreamVideoTime;
@end


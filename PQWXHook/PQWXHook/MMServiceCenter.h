//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NSMutableDictionary, NSRecursiveLock;

@interface MMServiceCenter : NSObject
{
    NSMutableDictionary *m_dicService;
    NSRecursiveLock *m_lock;
}

+ (id)defaultCenter;
- (void)callClearData;
- (void)callEnterBackground;
- (void)callEnterForeground;
- (void)callReloadData;
- (void)callServiceMemoryWarning;
- (void)callTerminate;
- (void)dealloc;
- (id)getService:(Class)arg1;
- (id)init;
- (void)removeService:(Class)arg1;

@end


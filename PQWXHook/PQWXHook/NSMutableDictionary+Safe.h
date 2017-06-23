//
//  NSMutableDictionary+Safe.h
//  PQWXHook
//
//  Created by 黄盼青 on 16/3/10.
//  Copyright © 2016年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (Safe)

-(void)pq_setSafeObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

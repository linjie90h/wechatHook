//
//  NSMutableDictionary+Safe.m
//  PQWXHook
//
//  Created by 黄盼青 on 16/3/10.
//  Copyright © 2016年 tencent. All rights reserved.
//

#import "NSMutableDictionary+Safe.h"

@implementation NSMutableDictionary (Safe)


-(void)pq_setSafeObject:(id)anObject forKey:(id<NSCopying>)aKey {
    
    if(anObject != nil) {
        
        [self setObject:anObject forKey:aKey];
        
    }
    
}


@end

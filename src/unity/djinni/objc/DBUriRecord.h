// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import <Foundation/Foundation.h>

@interface DBUriRecord : NSObject
- (nonnull instancetype)initWithScheme:(nonnull NSString *)scheme
                                  path:(nonnull NSString *)path
                                 items:(nonnull NSDictionary<NSString *, NSString *> *)items;
+ (nonnull instancetype)uriRecordWithScheme:(nonnull NSString *)scheme
                                       path:(nonnull NSString *)path
                                      items:(nonnull NSDictionary<NSString *, NSString *> *)items;

@property (nonatomic, readonly, nonnull) NSString * scheme;

@property (nonatomic, readonly, nonnull) NSString * path;

@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> * items;

@end

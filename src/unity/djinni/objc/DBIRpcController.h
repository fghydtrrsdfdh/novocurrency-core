// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import <Foundation/Foundation.h>
@protocol DBIRpcListener;


/** C++ interface to execute RPC commands */
@interface DBIRpcController : NSObject

+ (void)execute:(nonnull NSString *)rpcCommandLine
 resultListener:(nullable id<DBIRpcListener>)resultListener;

+ (nonnull NSArray<NSString *> *)getAutocompleteList;

@end

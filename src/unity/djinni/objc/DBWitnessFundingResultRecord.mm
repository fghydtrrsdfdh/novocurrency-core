// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBWitnessFundingResultRecord.h"


@implementation DBWitnessFundingResultRecord

- (nonnull instancetype)initWithStatus:(nonnull NSString *)status
                                  txid:(nonnull NSString *)txid
                                   fee:(int64_t)fee
{
    if (self = [super init]) {
        _status = [status copy];
        _txid = [txid copy];
        _fee = fee;
    }
    return self;
}

+ (nonnull instancetype)witnessFundingResultRecordWithStatus:(nonnull NSString *)status
                                                        txid:(nonnull NSString *)txid
                                                         fee:(int64_t)fee
{
    return [(DBWitnessFundingResultRecord*)[self alloc] initWithStatus:status
                                                                  txid:txid
                                                                   fee:fee];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p status:%@ txid:%@ fee:%@>", self.class, (void *)self, self.status, self.txid, @(self.fee)];
}

@end

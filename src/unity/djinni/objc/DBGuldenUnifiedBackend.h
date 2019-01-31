// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBAddressRecord.h"
#import "DBBlockinfoRecord.h"
#import "DBMonitorRecord.h"
#import "DBMutationRecord.h"
#import "DBPeerRecord.h"
#import "DBQrcodeRecord.h"
#import "DBTransactionRecord.h"
#import "DBUriRecipient.h"
#import "DBUriRecord.h"
#import <Foundation/Foundation.h>
@protocol DBGuldenMonitorListener;
@protocol DBGuldenUnifiedFrontend;

/** Interface constants */
extern int32_t const DBGuldenUnifiedBackendVersion;

/** This interface will be implemented in C++ and can be called from any language. */
@interface DBGuldenUnifiedBackend : NSObject

/** Start the library */
+ (int32_t)InitUnityLib:(nonnull NSString *)dataDir
                testnet:(BOOL)testnet
                signals:(nullable id<DBGuldenUnifiedFrontend>)signals;

/** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
+ (BOOL)InitWalletFromRecoveryPhrase:(nonnull NSString *)phrase;

/** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
+ (BOOL)InitWalletLinkedFromURI:(nonnull NSString *)linkedUri;

/** Replace the existing wallet accounts with a new one from a linked URI - only after first emptying the wallet. */
+ (BOOL)ReplaceWalletLinkedFromURI:(nonnull NSString *)linkedUri;

/** Check link URI for validity */
+ (BOOL)IsValidLinkURI:(nonnull NSString *)phrase;

/**
 * Check recovery phrase for (syntactic) validity
 * Considered valid if the contained mnemonic is valid and the birthnumber is either absent or passes Base-10 checksum
 */
+ (BOOL)IsValidRecoveryPhrase:(nonnull NSString *)phrase;

/** Generate a new recovery mnemonic */
+ (nonnull NSString *)GenerateRecoveryMnemonic;

/** Stop the library */
+ (void)TerminateUnityLib;

/** Generate a QR code for a string, QR code will be as close to widthHint as possible when applying simple scaling. */
+ (nonnull DBQrcodeRecord *)QRImageFromString:(nonnull NSString *)qrString
                                    widthHint:(int32_t)widthHint;

/** Get a receive address from the wallet */
+ (nonnull NSString *)GetReceiveAddress;

/** Get a receive address from the wallet */
+ (nonnull NSString *)GetRecoveryPhrase;

/** Rescan blockchain for wallet transactions */
+ (void)DoRescan;

/** Check if text/address is something we are capable of sending money too */
+ (nonnull DBUriRecipient *)IsValidRecipient:(nonnull DBUriRecord *)request;

/** Attempt to pay a recipient, will throw on failure with descriptiopn */
+ (void)performPaymentToRecipient:(nonnull DBUriRecipient *)request;

/** Get list of all transactions wallet has been involved in */
+ (nonnull NSArray<DBTransactionRecord *> *)getTransactionHistory;

/**
 * Get the wallet transaction for the hash
 * Will throw if not found
 */
+ (nonnull DBTransactionRecord *)getTransaction:(nonnull NSString *)txHash;

/** Get list of wallet mutations */
+ (nonnull NSArray<DBMutationRecord *> *)getMutationHistory;

/** Get list of all address book entries */
+ (nonnull NSArray<DBAddressRecord *> *)getAddressBookRecords;

/** Add a record to the address book */
+ (void)addAddressBookRecord:(nonnull DBAddressRecord *)address;

/** Delete a record from the address book */
+ (void)deleteAddressBookRecord:(nonnull DBAddressRecord *)address;

/** Interim persist and prune of state. Use at key moments like app backgrounding. */
+ (void)PersistAndPruneForSPV;

/**
 * Reset progress notification. In cases where there has been no progress for a long time, but the process
 * is still running the progress can be reset and will represent work to be done from this reset onwards.
 * For example when the process is in the background on iOS for a long long time (but has not been terminated
 * by the OS) this might make more sense then to continue the progress from where it was a day or more ago.
 */
+ (void)ResetUnifiedProgress;

/** Get connected peer info */
+ (nonnull NSArray<DBPeerRecord *> *)getPeers;

/** Get info of last blocks (at most 32) in SPV chain */
+ (nonnull NSArray<DBBlockinfoRecord *> *)getLastSPVBlockinfos;

+ (nonnull DBMonitorRecord *)getMonitoringStats;

+ (void)RegisterMonitorListener:(nullable id<DBGuldenMonitorListener>)listener;

+ (void)UnregisterMonitorListener:(nullable id<DBGuldenMonitorListener>)listener;

@end

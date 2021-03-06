// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

struct BalanceRecord;
struct MutationRecord;
struct TransactionRecord;

/** Interface to receive wallet level events */
#ifdef DJINNI_NODEJS
#include "NJSIWalletListener.hpp" 
#define IWalletListener NJSIWalletListener
#else

class IWalletListener {
public:
    virtual ~IWalletListener() {}

    virtual void notifyBalanceChange(const BalanceRecord & new_balance) = 0;

    /**
     * Notification of new mutations.
     * If self_committed it is due to a call to performPaymentToRecipient, else it is because of a transaction
     * reached us in another way. In general this will be because we received funds from someone, hower there are
     * also cases where funds is send from our wallet while !self_committed (for example by a linked desktop wallet
     * or another wallet instance using the same keys as ours).
     */
    virtual void notifyNewMutation(const MutationRecord & mutation, bool self_committed) = 0;

    virtual void notifyUpdatedTransaction(const TransactionRecord & transaction) = 0;
};
#endif

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBBalanceRecord+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto BalanceRecord::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::I64::toCpp(obj.availableIncludingLocked),
            ::djinni::I64::toCpp(obj.availableExcludingLocked),
            ::djinni::I64::toCpp(obj.availableLocked),
            ::djinni::I64::toCpp(obj.unconfirmedIncludingLocked),
            ::djinni::I64::toCpp(obj.unconfirmedExcludingLocked),
            ::djinni::I64::toCpp(obj.unconfirmedLocked),
            ::djinni::I64::toCpp(obj.immatureIncludingLocked),
            ::djinni::I64::toCpp(obj.immatureExcludingLocked),
            ::djinni::I64::toCpp(obj.immatureLocked),
            ::djinni::I64::toCpp(obj.totalLocked)};
}

auto BalanceRecord::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[DBBalanceRecord alloc] initWithAvailableIncludingLocked:(::djinni::I64::fromCpp(cpp.availableIncludingLocked))
                                            availableExcludingLocked:(::djinni::I64::fromCpp(cpp.availableExcludingLocked))
                                                     availableLocked:(::djinni::I64::fromCpp(cpp.availableLocked))
                                          unconfirmedIncludingLocked:(::djinni::I64::fromCpp(cpp.unconfirmedIncludingLocked))
                                          unconfirmedExcludingLocked:(::djinni::I64::fromCpp(cpp.unconfirmedExcludingLocked))
                                                   unconfirmedLocked:(::djinni::I64::fromCpp(cpp.unconfirmedLocked))
                                             immatureIncludingLocked:(::djinni::I64::fromCpp(cpp.immatureIncludingLocked))
                                             immatureExcludingLocked:(::djinni::I64::fromCpp(cpp.immatureExcludingLocked))
                                                      immatureLocked:(::djinni::I64::fromCpp(cpp.immatureLocked))
                                                         totalLocked:(::djinni::I64::fromCpp(cpp.totalLocked))];
}

}  // namespace djinni_generated

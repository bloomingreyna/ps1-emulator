#pragma once

#include <cstdint>

enum class ctl_reg : std::size_t
{
    INDX = 0,
    RAND = 1,
    TLBL = 2,
    BPC = 3,
    CTXT = 4,
    BDA = 5,
    PIDMASK = 6,
    DCIC = 7,
    BADV = 8,
    BDAM = 9,
    TLBH = 10,
    BPCM = 11,
    SR = 12,
    CAUSE = 13,
    EPC = 14,
    PRID = 15
};

enum class exception_type : uint32_t
{
    INT = 0,
    MOD = 1,
    TLBL = 2,
    TLBS = 3,
    ADEL = 4,
    ADES = 5,
    IBE = 6,
    DBE = 7,
    SYSCALL = 8,
    BP = 9,
    RI = 10,
    CPU = 11,
    OV = 12
};

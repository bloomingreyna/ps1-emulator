// TODO

#pragma once

#include <array>
#include <cstdint>

enum class sysctlproc_register
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

class system_control_processor
{
public:
    uint32_t get_cr(std::size_t index) const;
    uint32_t set_cr(std::size_t index, uint32_t value);
private:
    std::array<uint32_t, 32> control_registers{};
};

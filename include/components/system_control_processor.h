#pragma once

#include <array>
#include <cstdint>

class sysctlproc
{
public:
    uint32_t get_cr(std::size_t index) const;
    void set_cr(std::size_t index, uint32_t value);
private:
    std::array<uint32_t, 32> ctl_regs{};
};

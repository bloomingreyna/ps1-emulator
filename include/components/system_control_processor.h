// TODO

#pragma once

#include <array>
#include <cstdint>

class system_control_processor
{
public:
    uint32_t get_cr(std::size_t index) const;
    uint32_t set_cr(std::size_t index, uint32_t value);
private:
    std::array<uint32_t, 32> control_registers{};
};

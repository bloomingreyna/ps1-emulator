#pragma once

#include <cstdint>

enum class special_function : uint32_t
{
    ADD = 0x20, ADDU = 0x21,
    AND = 0x24
};

struct opcode
{
    uint32_t value{};

    uint32_t op();
    uint32_t src_reg();
    uint32_t target_reg();
    uint32_t immediate();
    uint32_t target_addr();
    uint32_t dest_reg();
    uint32_t shift_amt();
    uint32_t function();
};

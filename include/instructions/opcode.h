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

    uint32_t op() const;
    uint32_t src_reg() const;
    uint32_t target_reg() const;
    uint32_t immediate() const;
    uint32_t target_addr() const;
    uint32_t dest_reg() const;
    uint32_t shift_amt() const;
    uint32_t function() const;

    // Functionally identical to other opcode parameters, but implemented for code readability
    uint32_t base_addr() const;
    uint32_t offset() const;
};

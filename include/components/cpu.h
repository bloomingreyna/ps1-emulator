#pragma once

#include <array>
#include <cstdint>

#include "components/mult_div_unit.h"
#include "components/system_control_processor.h"

enum class md_operations
{
    MULT, MULTU,
    DIV, DIVU
};

class cpu
{
public:
    void execute_instruction();

    void multiply(int64_t lhs, int64_t rhs);
    void multiply(uint64_t lhs, uint64_t rhs);
    void divide(int32_t dividend, int32_t divisor);
    void divide(uint32_t dividend, uint32_t divisor);

    uint32_t get_gpr(std::size_t index) const;
    uint32_t get_pc() const;
    uint32_t get_hi() const;
    uint32_t get_lo() const;

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);
    void set_hi(uint32_t value);
    void set_lo(uint32_t value);

private:
    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};

    mult_div_unit md_unit{};
    system_control_processor sysctlproc{};
};

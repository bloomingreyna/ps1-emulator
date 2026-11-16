#include "components/cpu.h"

namespace
{
    constexpr unsigned int MULT_CYCLES{12};
    constexpr unsigned int DIV_CYCLES{35};
}

void cpu::multiply(int64_t lhs, int64_t rhs) { md_unit.multiply(lhs, rhs); }
void cpu::multiply(uint64_t lhs, uint64_t rhs) { md_unit.multiply(lhs, rhs); }
void cpu::divide(int32_t lhs, int32_t rhs) { md_unit.divide(lhs, rhs); }
void cpu::divide(uint32_t lhs, uint32_t rhs) { md_unit.divide(lhs, rhs); }

void mult_div_unit::tick()
{
    if (op_time_remaining > 0)
    {
        executing = true;
        if (--op_time_remaining == 0)
        {
            hi = operation_queue.front().hi;
            lo = operation_queue.front().lo;
            executing = false;
            operation_queue.pop();
        }
    }

    if (!operation_queue.empty()) { op_time_remaining = operation_queue.front().delay; }
}

void mult_div_unit::multiply(int64_t lhs, int64_t rhs)
{
    int64_t result{lhs * rhs};
    md_operation op{
        .hi = static_cast<uint32_t>(result >> 32),
        .lo = static_cast<uint32_t>(result),
        .delay = MULT_CYCLES
    };
    operation_queue.push(op);
}

void mult_div_unit::multiply(uint64_t lhs, uint64_t rhs)
{
    uint64_t result{lhs * rhs};
    md_operation op{
        .hi = static_cast<uint32_t>(result >> 32),
        .lo = static_cast<uint32_t>(result),
        .delay = MULT_CYCLES
    };
    operation_queue.push(op);
}

void mult_div_unit::divide(int32_t dividend, int32_t divisor)
{
    int32_t result;
    int32_t remainder;
    if (divisor != 0)
    {
        if (dividend < 0) { result = 0x00000001; }
        else { result = 0xFFFFFFFF; }
        remainder = dividend;
    }
    else
    {
        result = dividend / divisor;
        remainder = dividend % divisor;
    }

    md_operation op{
        .hi = static_cast<uint32_t>(remainder),
        .lo = static_cast<uint32_t>(result),
        .delay = DIV_CYCLES
    };
    operation_queue.push(op);
}

void mult_div_unit::divide(uint32_t dividend, uint32_t divisor)
{
    uint32_t result;
    uint32_t remainder;
    if (divisor != 0)
    {
        result = 0xFFFFFFFF;
        remainder = dividend;
    }
    else
    {
        result = dividend / divisor;
        remainder = dividend % divisor;
    }

    md_operation op{
        .hi = remainder,
        .lo = result,
        .delay = DIV_CYCLES
    };
    operation_queue.push(op);
}

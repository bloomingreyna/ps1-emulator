#include "components/mult_div_unit.h"
#include "components/cpu.h"

namespace
{
    constexpr unsigned int MULT_CYCLES{12};
    constexpr unsigned int DIV_CYCLES{35};
}

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

void cpu::multiply(int64_t lhs, int64_t rhs)
{
    int64_t result{lhs * rhs};
    md_operation op{
        .hi = static_cast<uint32_t>(result >> 32),
        .lo = static_cast<uint32_t>(result),
        .delay = MULT_CYCLES
    };
    md_unit.operation_queue.push(op);
}

void cpu::multiply(uint64_t lhs, uint64_t rhs)
{
    uint64_t result{lhs * rhs};
    md_operation op{
        .hi = static_cast<uint32_t>(result >> 32),
        .lo = static_cast<uint32_t>(result),
        .delay = MULT_CYCLES
    };
    md_unit.operation_queue.push(op);
}

void cpu::divide(int32_t dividend, int32_t divisor)
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
    md_unit.operation_queue.push(op);
}

void cpu::divide(uint32_t dividend, uint32_t divisor)
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
    md_unit.operation_queue.push(op);
}

#include "components/cpu.h"
#include "utils/exceptions.h"

bool add_integer_overflow(uint32_t lhs, uint32_t rhs)
{
    return ((lhs ^ rhs ^ (lhs + rhs)) & 0x80000000) != 0;
}

bool sub_integer_overflow(uint32_t lhs, uint32_t rhs)
{
    return ((lhs ^ rhs ^ (lhs - rhs)) & 0x80000000) == 0;
}

bool alignment_error(uint32_t addr, data_size alignment, cpu& c)
{
    c.set_problem_addr(addr);
    switch (alignment)
    {
        case data_size::BYTE:
        {
            return false;
        }
        case data_size::HALF_WORD:
        {
            return (addr & 0b1) != 0;
        }
        case data_size::WORD:
        {
            return (addr & 0b11) != 0;
        }
    }
    return false;
}

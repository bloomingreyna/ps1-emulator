#include <utils/exceptions.h>

bool add_integer_overflow(uint32_t lhs, uint32_t rhs)
{
    return ((lhs ^ rhs ^ (lhs + rhs)) & 0x80000000) != 0;
}

bool sub_integer_overflow(uint32_t lhs, uint32_t rhs)
{
    return ((lhs ^ rhs ^ (lhs - rhs)) & 0x80000000) == 0;
}

bool alignment_error(uint32_t addr, data_size alignment)
{

}

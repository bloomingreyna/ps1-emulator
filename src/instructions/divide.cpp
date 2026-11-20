#include "instructions/instructions.h"

void divide_word(cpu& c, opcode o)
{
    int64_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int64_t target{static_cast<int32_t>(c.get_gpr(o.target_reg()))};

    int32_t result{};
    int32_t remainder{};

    if (target != 0)
    {
        result = src / target;
        remainder = src % target;
    }
    else
    {
        if (src < 0)
        {
            result = 0x00000001;
        }
        else
        {
            result = 0xFFFFFFFF;
        }
        remainder = src;
    }

    c.set_hi(remainder);
    c.set_lo(result);
}

void divide_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};

    uint32_t result{};
    uint32_t remainder{};

    if (target != 0)
    {
        result = src / target;
        remainder = src % target;
    }
    else
    {
        result = 0xFFFFFFFF;
        remainder = src;
    }

    c.set_hi(remainder);
    c.set_lo(result);
}

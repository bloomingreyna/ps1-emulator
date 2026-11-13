#include "instructions/instructions.h"

void divide_word(cpu& c, opcode o)
{
    int32_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int32_t target{static_cast<int32_t>(c.get_gpr(o.target_reg()))};

    if (target == 0)
    {
        c.set_hi(target, 36);
        if (target < 0) { c.set_lo(0x00000001, 36); }
        else { c.set_lo(0xFFFFFFFF, 36); }
    }
    else
    {
        c.set_hi(src % target, 36);
        c.set_lo(src / target, 36);
    }
}

void divide_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};

    if (target == 0)
    {
        c.set_hi(target, 36);
        c.set_hi(0xFFFFFFFF, 36);
    }
    else
    {
        c.set_hi(src % target, 36);
        c.set_lo(src / target, 36);
    }
}

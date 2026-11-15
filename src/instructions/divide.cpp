#include "instructions/instructions.h"

void divide_word(cpu& c, opcode o)
{
    int32_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int32_t target{static_cast<int32_t>(c.get_gpr(o.target_reg()))};
    c.md_unit.divide(src, target);
}

void divide_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.md_unit.divide(src, target);
}

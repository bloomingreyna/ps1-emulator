#include "instructions/instructions.h"

void multiply_word(cpu& c, opcode o)
{
    int64_t src{static_cast<int64_t>(c.get_gpr(o.src_reg()))};
    int64_t target{static_cast<int64_t>(c.get_gpr(o.target_reg()))};
    c.md_unit.multiply(src, target);
}

void multiply_uword(cpu& c, opcode o)
{
    uint64_t src{c.get_gpr(o.src_reg())};
    uint64_t target{c.get_gpr(o.target_reg())};
    c.md_unit.multiply(src, target);
}

// TODO: Exceptions

#include "instructions/instructions.h"

void subtract_word(cpu& c, opcode o)
{
    int64_t src{c.get_gpr(o.src_reg())};
    int64_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src - target);
}

void subtract_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src - target);
}

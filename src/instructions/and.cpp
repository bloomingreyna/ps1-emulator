#include "instructions/instructions.h"

void and_reg(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src & target);
}

void and_imm(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t imm{o.immediate()};
    c.set_gpr(o.target_reg(), src & imm);
}

#include "instructions/instructions.h"

// TODO: Exception handling for signed addition

void add_word(cpu& c, opcode o)
{
    int64_t src{c.get_gpr(o.src_reg())};
    int64_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src + target);
}

void add_imm_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src + imm);
}

void add_imm_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src + imm);
}

void add_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src + target);
}

#include "instructions/instructions.h"

// TODO: Exception handling for signed addition

void instructions::add_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src + target);
}

void instructions::add_imm_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t imm{o.immediate()};
    if ((imm & 0x8000) != 0) { imm |= 0xFFFF0000; }

    c.set_gpr(o.target_reg(), src + imm);
}

void instructions::add_imm_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t imm{o.immediate()};
    if ((imm & 0x8000) != 0) { imm |= 0xFFFF0000; }

    c.set_gpr(o.target_reg(), src + imm);
}

void instructions::add_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src + target);
}

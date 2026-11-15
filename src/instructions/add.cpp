#include "instructions/instructions.h"

// TODO: Exception handling for signed addition

void add_word(cpu& c, opcode o)
{
    int32_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int32_t target{static_cast<int32_t>(c.get_gpr(o.target_reg()))};
    c.set_gpr(o.dest_reg(), src + target);
}

void add_imm_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src + static_cast<uint32_t>(imm));
}

void add_imm_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src + static_cast<uint32_t>(imm));
}

void add_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src + target);
}

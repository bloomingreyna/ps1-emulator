#include "instructions/instructions.h"

void set_on_less_than(cpu& c, opcode o)
{
    int32_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int32_t target{static_cast<int32_t>(c.get_gpr(o.target_reg()))};
    c.set_gpr(o.dest_reg(), src < target);
}

void set_on_less_than_imm(cpu& c, opcode o)
{
    int32_t src{static_cast<int32_t>(c.get_gpr(o.src_reg()))};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src < imm);
}

void set_on_less_than_imm_unsigned(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    c.set_gpr(o.target_reg(), src < static_cast<uint32_t>(imm));
}

void set_on_less_than_unsigned(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src < target);
}

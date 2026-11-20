#include "instructions/instructions.h"

void jump(cpu& c, opcode o)
{
    uint32_t target{o.target_addr()};
    uint32_t pc_high_order{c.get_pc() & 0xFF000000};
    c.prepare_jump((target << 2) | pc_high_order);
}

void jump_and_link(cpu& c, opcode o)
{
    uint32_t target{o.target_addr()};
    uint32_t pc_high_order{c.get_pc() & 0xFF000000};
    c.set_gpr(31, c.get_pc() + 4);
    c.prepare_jump((target << 2) | pc_high_order);
}

void jump_and_link_register(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    c.prepare_jump(src);
    c.set_gpr(o.dest_reg(), c.get_pc() + 4);
}

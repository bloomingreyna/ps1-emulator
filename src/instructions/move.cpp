#include "instructions/instructions.h"

// TODO: Coprocessor moves, CPU stalling on incomplete MULT/DIV

void move_from_hi(cpu& c, opcode o)
{
    c.set_gpr(o.dest_reg(), c.get_hi());
}

void move_from_lo(cpu& c, opcode o)
{
    c.set_gpr(o.dest_reg(), c.get_lo());
}

void move_to_hi(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    c.set_hi(src);
}

void move_to_lo(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    c.set_lo(src);
}

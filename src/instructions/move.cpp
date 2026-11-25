#include "instructions/instructions.h"

void move_from_coprocessor(cpu& c, opcode o)
{
    switch (o.coprocessor())
    {
        case 0:
        {
            uint32_t dest{c.get_scp_cr(o.dest_reg())};
            c.set_gpr(o.target_reg(), dest);
            break;
        }
    }
}

void move_from_hi(cpu& c, opcode o)
{
    c.set_gpr(o.dest_reg(), c.get_hi());
}

void move_from_lo(cpu& c, opcode o)
{
    c.set_gpr(o.dest_reg(), c.get_lo());
}

void move_to_coprocessor(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    switch (o.coprocessor())
    {
        case 0:
        {
            c.set_scp_cr(o.dest_reg(), target);
            break;
        }
    }
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

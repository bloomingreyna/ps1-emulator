#include "instructions/instructions.h"
#include "utils/exceptions.h"

// TODO: Exception
void subtract_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    if (sub_integer_overflow(src, target))
    {
        c.throw_exception();
        return;
    }
    c.set_gpr(o.dest_reg(), src - target);
}

void subtract_uword(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src - target);
}

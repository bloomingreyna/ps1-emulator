#include "components/system_control_processor.h"
#include "instructions/instructions.h"
#include "utils/exceptions.h"

// TODO: Exception handling for signed addition

void add_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    if (add_integer_overflow(src, target))
    {
        c.throw_exception(exception_type::OV);
        return;
    }
    c.set_gpr(o.dest_reg(), src + target);
}

void add_imm_word(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t imm{static_cast<int16_t>(o.immediate())};
    if (add_integer_overflow(src, imm))
    {
        c.throw_exception(exception_type::OV);
        return;
    }
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

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

void nor_reg(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), ~(src | target));
}

void or_reg(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src | target);
}

void or_imm(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t imm{o.immediate()};
    c.set_gpr(o.target_reg(), src | imm);
}

void shift_word_left_logical(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), target << o.shift_amt());
}

void shift_word_left_logical_var(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), target << (src & 0x1F));
}

void shift_word_right_arithmetic(cpu& c, opcode o)
{
    int64_t target{static_cast<int64_t>(c.get_gpr(o.target_reg()))};
    c.set_gpr(o.dest_reg(), target >> o.shift_amt());
}

void shift_word_right_arithmetic_var(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int64_t target{static_cast<int64_t>(c.get_gpr(o.target_reg()))};
    c.set_gpr(o.dest_reg(), target >> (src & 0x1F));
}

void shift_word_right_logical(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), target >> o.shift_amt());
}

void shift_word_right_logical_var(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), target >> (src & 0x1F));
}

void exclusive_or(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    c.set_gpr(o.dest_reg(), src ^ target);
}

void exclusive_or_imm(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t imm{o.immediate()};
    c.set_gpr(o.target_reg(), src ^ imm);
}

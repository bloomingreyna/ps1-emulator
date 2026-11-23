#include "instructions/instructions.h"

void branch_equal(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if (src == target)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_greater_equal_zero(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if ((src & 0x80000000) == 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_greater_equal_zero_link(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.set_gpr(31, c.get_pc() + (offset << 2));
    if ((src & 0x80000000) == 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_greater_zero(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if ((src & 0x80000000) == 0 && src != 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_less_equal_zero(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if ((src & 0x80000000) != 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_less_zero(cpu&c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if ((src & 0x80000000) != 0 && src != 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_less_zero_link(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.set_gpr(31, c.get_pc() + (offset << 2));
    if ((src & 0x80000000) != 0 && src != 0)
    {
        c.prepare_branch(offset << 2);
    }
}

void branch_not_equal(cpu& c, opcode o)
{
    uint32_t src{c.get_gpr(o.src_reg())};
    uint32_t target{c.get_gpr(o.target_reg())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    if (src != target)
    {
        c.prepare_branch(offset << 2);
    }
}

#include "components/cpu.h"

void cpu::prepare_branch(int32_t offset)
{
    pc_change_vars.new_pc = pc + offset;
    pc_change_vars.changing_pc = true;
}

void cpu::prepare_jump(uint32_t addr)
{
    pc_change_vars.new_pc = pc;
    pc_change_vars.changing_pc = true;
}

#include "components/cpu.h"
#include "components/ps1.h"

void cpu::prepare_branch(int32_t offset)
{
    system.read_memory(pc + 4 + offset); // Bus error built into read function
    if (!exception_thrown)
    {
        pc_change_vars.intermediate_new_pc = pc + 4 + offset;
        pc_change_vars.changing_pc = true;
    }
}

void cpu::prepare_jump(uint32_t addr)
{
    system.read_memory(addr); // Bus error built into read function
    if (!exception_thrown)
    {
        pc_change_vars.intermediate_new_pc = addr;
        pc_change_vars.changing_pc = true;
    }
}

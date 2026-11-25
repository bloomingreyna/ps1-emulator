#include "components/cpu.h"
#include "components/ps1.h"
#include "utils/cpu_enums.h"
#include "utils/exceptions.h"
#include "utils/sysctlproc_enums.h"

void cpu::prepare_branch(int32_t offset)
{
    uint32_t addr{pc + 4 + offset};
    if (alignment_error(addr, data_size::WORD))
    {
        throw_exception(exception_type::ADEL);
        return;
    }

    system.read_memory(addr); // Bus error built into read function
    if (!exception_thrown)
    {
        pc_change_vars.intermediate_new_pc = addr;
        pc_change_vars.changing_pc = true;
    }
}

void cpu::prepare_jump(uint32_t addr)
{
    if (alignment_error(addr, data_size::WORD))
    {
        throw_exception(exception_type::ADEL);
        return;
    }

    system.read_memory(addr); // Bus error built into read function
    if (!exception_thrown)
    {
        pc_change_vars.intermediate_new_pc = addr;
        pc_change_vars.changing_pc = true;
    }
}

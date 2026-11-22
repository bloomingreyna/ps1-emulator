#include <components/cpu.h>
#include <components/system_control_processor.h>

void cpu::throw_exception(exception_type e)
{
    if (pc_change_vars.changing_pc)
    {
        sysctlproc.set_cr(static_cast<std::size_t>(sysctlproc_register::EPC), pc - 4);
    }
    else
    {
        sysctlproc.set_cr(static_cast<std::size_t>(sysctlproc_register::EPC), pc);
    }
}

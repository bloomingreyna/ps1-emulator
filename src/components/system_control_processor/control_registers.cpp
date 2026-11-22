#include "components/system_control_processor.h"

uint32_t sysctlproc::get_cr(std::size_t index) const
{
    return ctl_regs[index];
}

void sysctlproc::set_cr(std::size_t index, uint32_t value)
{
    ctl_regs[index] = value;
}

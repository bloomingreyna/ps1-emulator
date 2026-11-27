#include "components/system_control_processor.h"
#include "utils/sysctlproc_enums.h"

uint32_t sysctlproc::get_cr(std::size_t index) const
{
    uint32_t data{ctl_regs[index]};
    if (index == static_cast<uint32_t>(ctl_reg::CAUSE))
    {
        data &= ~0b11;
    }
    return data;
}

void sysctlproc::set_cr(std::size_t index, uint32_t value)
{
    ctl_regs[index] = value;
}

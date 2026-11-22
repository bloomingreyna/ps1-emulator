#include "components/cpu.h"
#include "components/system_control_processor.h"
#include "utils/sysctlproc_enums.h"

void cpu::throw_exception(exception_type e)
{
    exception_thrown = true;

    if (pc_change_vars.changing_pc)
    {
        scp.set_cr(static_cast<std::size_t>(ctl_reg::EPC), pc - 4);
    }
    else
    {
        scp.set_cr(static_cast<std::size_t>(ctl_reg::EPC), pc);
    }

    scp.set_cr(static_cast<std::size_t>(ctl_reg::CAUSE), static_cast<uint32_t>(e));

    if (!scp.get_bev())
    {
        pc_change_vars.new_pc = 0x80000000;
    }
    else
    {
        pc_change_vars.new_pc = 0xBFC00180;
    }
}

#include "components/cpu.h"
#include "components/system_control_processor.h"
#include "utils/sysctlproc_enums.h"

void cpu::throw_exception(exception_type e)
{
    exception_thrown = true;

    uint32_t cause_value{scp.get_cr(static_cast<std::size_t>(ctl_reg::CAUSE)) & ~(0x7C | 0x80000000)};
    cause_value |= static_cast<uint32_t>(e) << 2;

    if (pc_change_vars.changing_pc)
    {
        scp.set_cr(static_cast<std::size_t>(ctl_reg::EPC), pc - 4);
        cause_value |= 1 << 31;
    }
    else
    {
        scp.set_cr(static_cast<std::size_t>(ctl_reg::EPC), pc);
    }

    scp.set_cr(static_cast<std::size_t>(ctl_reg::CAUSE), cause_value);

    if (e == exception_type::ADEL || e == exception_type::ADES)
    {
        scp.set_cr(static_cast<std::size_t>(ctl_reg::BADV), problematic_addr);
    }

    uint32_t sr_value{scp.get_cr(static_cast<std::size_t>(ctl_reg::SR))};
    uint32_t kernel_interrupt_stack_push{(sr_value << 2) & 0x3C};
    sr_value &= ~0x3F;
    sr_value |= kernel_interrupt_stack_push;
}

void cpu::jump_to_exception_vec()
{
    if ((scp.get_cr(static_cast<std::size_t>(ctl_reg::SR)) & (1 << 22)) == 0)
    {
        pc_change_vars.new_pc = 0x80000000;
    }
    else
    {
        pc_change_vars.new_pc = 0xBFC00180;
    }
    pc = pc_change_vars.new_pc;
}

void cpu::set_problem_addr(uint32_t addr) { problematic_addr = addr; }

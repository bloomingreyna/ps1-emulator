#include "components/system_control_processor.h"
#include "utils/sysctlproc_enums.h"

bool sysctlproc::get_bev() const
{
    uint32_t sr{ctl_regs[static_cast<std::size_t>(ctl_reg::SR)]};
    return (sr & 0x00400000) != 0;
}

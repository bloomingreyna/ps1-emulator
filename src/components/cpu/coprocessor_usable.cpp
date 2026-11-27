#include "components/cpu.h"
#include "utils/sysctlproc_enums.h"

bool cpu::coprocessor_usable(uint32_t coprocessor)
{
    return (scp.get_cr(static_cast<std::size_t>(ctl_reg::SR)) & (1 << (28 + coprocessor))) != 0;
}

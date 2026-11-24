#include "components/cpu.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    if (index != 0) 
    {
        gprs[index] = value;
    }
    load_vars.write_occurred = true;
    load_vars.written_index_priority = index;
}

void cpu::set_pc(uint32_t value) { pc = value; }
void cpu::set_hi(uint32_t value) { hi = value; }
void cpu::set_lo(uint32_t value) { lo = value; }

void cpu::set_scp_cr(std::size_t index, uint32_t value)
{
    scp.set_cr(index, value);
}

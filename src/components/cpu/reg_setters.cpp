#include "components/cpu.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    if (index != 0) 
    {
        gprs[index] = value;
    }
    load_vars.cpu_write_occurred = true;
    load_vars.written_index_priority = index;
}

void cpu::set_pc(uint32_t value) { pc = value; }
void cpu::set_hi(uint32_t value) { hi = value; }
void cpu::set_lo(uint32_t value) { lo = value; }

// Use CPU dispatch functions to write to coprocessors if asserting write priority over loads. But direct loads are only accessible within the scope of the CPU anyway, so...

void cpu::set_scp_cr(std::size_t index, uint32_t value)
{
    load_vars.coprocessor_write_occured = true;
    load_vars.written_index_priority = index;
    load_vars.written_coprocessor_priority = 0;
    scp.set_cr(index, value);
}

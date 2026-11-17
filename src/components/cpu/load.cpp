#include "components/cpu.h"

void cpu::load_delayed()
{
    bool no_write_override{!write_occurred || load_index_buffer != written_index_priority};
    if (load_index_buffer != 0 && no_write_override) { gprs[load_index_buffer] = load_data_buffer; }
    delay_loading = false;
}

void cpu::prepare_delayed_load_signed(uint32_t addr, std::size_t index)
{
    load_index_buffer = index;
}

void cpu::prepare_delayed_load_unsigned(uint32_t addr, std::size_t index)
{
    load_index_buffer = index;
}

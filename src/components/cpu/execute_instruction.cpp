#include "components/cpu.h"

void cpu::execute_instruction()
{
    // TODO: Make sure of delay vs instant load behavior
    if (delay_loading && finish_delay_loading) { load_delayed(); }

    write_occurred = false;
    finish_delay_loading = delay_loading;
}

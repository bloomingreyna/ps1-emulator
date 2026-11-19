#include "components/cpu.h"

void cpu::tick()
{
    // Execution...
    if (load_vars.disable_special_load)
    {
        load_vars.special_load = false;
        load_vars.disable_special_load = false;
    }

    if (load_vars.delay_loading && load_vars.finish_delay_loading)
    {
        load();
    }
    load_vars.load_data = load_vars.intermediate_load_data;

    load_vars.write_occurred = false;
    load_vars.finish_delay_loading = load_vars.delay_loading;

    if (load_vars.special_load)
    {
        load_vars.disable_special_load = true;
    }
}

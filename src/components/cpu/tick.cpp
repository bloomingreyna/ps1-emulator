#include "components/cpu.h"

void cpu::tick()
{
    tick_fetch();
    tick_load_trigger();

    // Execution

    tick_pc_change();
    tick_load();
}

void cpu::tick_fetch()
{
    if (!pc_change_vars.changing_pc)
    {
        pc_change_vars.new_pc = pc + 4;
    }
    else
    {
        pc_change_vars.new_pc = pc_change_vars.intermediate_new_pc;
        pc_change_vars.changing_pc = false;
    }
}

void cpu::tick_load_trigger()
{
    if (load_vars.trigger_load)
    {
        load_vars.loading = true;
        load_vars.trigger_load = false;
    }
}

void cpu::tick_pc_change()
{
    pc = pc_change_vars.new_pc;
}

void cpu::tick_load()
{
    if (load_vars.loading)
    {
        bool no_write_override{
            !load_vars.write_occurred ||
            load_vars.load_index != load_vars.written_index_priority
        };

        if (load_vars.load_index != 0 && no_write_override)
        {
            gprs[load_vars.load_index] = load_vars.load_data;
        }

        if (load_vars.disable_special_load)
        {
            load_vars.special_load = false;
        }

        load_vars.loading = false;
    }
    load_vars.load_data = load_vars.intermediate_load_data;

    if (load_vars.special_load)
    {
        load_vars.disable_special_load = true;
    }

    load_vars.write_occurred = false;
}

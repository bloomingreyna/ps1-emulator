#include "components/cpu.h"

void cpu::tick()
{
    tick_fetch();
    // Execution

    tick_load();
    tick_pc_change();
}

void cpu::tick_fetch()
{
    pc++;
    if (pc_change_vars.changing_pc && pc_change_vars.finish_changing_pc)
    {
        pc = pc_change_vars.new_pc;
        if (pc_change_vars.disable_changing_pc)
        {
            pc_change_vars.changing_pc = false;
        }
    }
}

void cpu::tick_load()
{
    if (load_vars.loading && load_vars.finish_loading)
    {
        bool no_write_override{
            !load_vars.write_occurred ||
            load_vars.load_index != load_vars.written_index_priority
        };

        if (load_vars.load_index != 0 && no_write_override)
        {
            gprs[load_vars.load_index] = load_vars.load_data;
        }

        if (load_vars.disable_loading)
        {
            load_vars.loading = false;
        }

        if (load_vars.disable_special_load)
        {
            load_vars.special_load = false;
        }
    }
    load_vars.load_data = load_vars.intermediate_load_data;

    load_vars.finish_loading = load_vars.loading;
    load_vars.disable_loading = load_vars.loading;
    load_vars.disable_special_load = load_vars.special_load;

    load_vars.write_occurred = false;
}

void cpu::tick_pc_change()
{
    pc_change_vars.finish_changing_pc = pc_change_vars.changing_pc;
    pc_change_vars.disable_changing_pc = pc_change_vars.changing_pc;
}

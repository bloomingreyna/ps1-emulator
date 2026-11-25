#include "components/cpu.h"
#include "components/ps1.h"
#include "utils/cpu_enums.h"

void cpu::tick()
{
    fetch();
    load_trigger();

    if (!exception_thrown)
    {
        executing = true;
        execute();
        executing = false;
        pc = pc_change_vars.new_pc;
    }

    if (exception_thrown)
    {
        jump_to_exception_vec();
        exception_thrown = false;
    }

    load_logic();
}

bool cpu::is_executing() const { return executing; }

void cpu::fetch()
{
    o.value = 0;
    for (unsigned int i{}; i < 4; ++i)
    {
        o.value |= system.read_memory(pc + i) << (8 * i);
    }

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

void cpu::execute()
{

}

void cpu::load_trigger()
{
    if (load_vars.trigger_load)
    {
        load_vars.loading = true;
        load_vars.load_data = load_vars.intermediate_load_data;
        load_vars.load_index = load_vars.intermediate_load_index;
        load_vars.trigger_load = false;
    }
}

void cpu::load_logic()
{
    if (load_vars.loading)
    {
        switch (load_vars.target)
        {
            case load_target::CPU:
            {
                bool no_write_override{
                    !load_vars.cpu_write_occurred ||
                    load_vars.load_index != load_vars.written_index_priority
                };

                if (load_vars.load_index != 0 && no_write_override)
                {
                    gprs[load_vars.load_index] = load_vars.load_data;
                }

                break;
            }
            case load_target::COPROCESSOR:
            {
                bool no_write_override{
                    !load_vars.coprocessor_write_occured ||
                    load_vars.target_coprocessor != load_vars.written_coprocessor_priority ||
                    load_vars.load_index != load_vars.written_index_priority
                };

                if (no_write_override)
                {
                    switch (load_vars.target_coprocessor)
                    {
                        case 0:
                        {
                            scp.set_cr(load_vars.load_index, load_vars.load_data);
                            break;
                        }
                    }
                }

                break;
            }
        }

        if (load_vars.disable_special_load)
        {
            load_vars.special_load = false;
        }
        load_vars.loading = false;
    }

    if (load_vars.special_load)
    {
        load_vars.disable_special_load = true;
    }

    load_vars.cpu_write_occurred = false;
    load_vars.coprocessor_write_occured = false;
}

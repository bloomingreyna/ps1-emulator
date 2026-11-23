#include "components/cpu.h"
#include "utils/cpu_enums.h"
#include "utils/exceptions.h"
#include "utils/sysctlproc_enums.h"

void cpu::tick()
{
    fetch();
    load_trigger();

    if (!exception_thrown)
    {
        execute();
    }
    else
    {
        jump_to_exception_vec();
        exception_thrown = false;
    }
    pc = pc_change_vars.new_pc;

    load_logic();
}

void cpu::fetch()
{
    if (!pc_change_vars.changing_pc)
    {
        pc_change_vars.new_pc = pc + 4;
    }
    else
    {
        if (!alignment_error(pc_change_vars.intermediate_new_pc, data_size::WORD))
        {
            pc_change_vars.new_pc = pc_change_vars.intermediate_new_pc;
        }
        else
        {
            throw_exception(exception_type::ADEL);
        }
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
        load_vars.trigger_load = false;
    }
}

void cpu::load_logic()
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

    if (load_vars.special_load)
    {
        load_vars.disable_special_load = true;
    }

    load_vars.write_occurred = false;
}

#include "components/cpu.h"

void cpu::execute_instruction()
{
    md_unit.tick();

    // TODO: Make sure of delay vs instant load behavior
    if (load_mem && delay_load_flag) {
        load();
        load_mem = false;
    }

    write_occurred = false;
    delay_load_flag = load_mem;
}

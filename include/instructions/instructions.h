#pragma once

#include "components/cpu.h"
#include "instructions/opcode.h"

namespace instructions
{
    void special_dispatch(cpu& c, opcode o);

    void add_word(cpu& c, opcode o);
    void add_imm_word(cpu& c, opcode o);
    void add_imm_uword(cpu& c, opcode o);
    void add_uword(cpu& c, opcode o);

    void and_reg(cpu& c, opcode o);
    void and_imm(cpu& c, opcode o);

    void branch_equal(cpu& c, opcode o);
    void branch_greater_equal_zero(cpu& c, opcode o);
    void branch_greater_equal_zero_link(cpu& c, opcode o);
    void branch_greater_zero(cpu& c, opcode o);
    void branch_less_equal_zero(cpu& c, opcode o);
    void branch_less_zero(cpu&c, opcode o);
    void branch_less_zero_link(cpu& c, opcode o);
    void branch_not_equal(cpu& c, opcode o);

    // TODO: BREAK and coprocessor stuff

    void divide_word(cpu& c, opcode o);
}

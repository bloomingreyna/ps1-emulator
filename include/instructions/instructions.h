#pragma once

#include "components/cpu.h"
#include "instructions/opcode.h"

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
void divide_uword(cpu& c, opcode o);

void jump(cpu& c, opcode o);
void jump_and_link(cpu& c, opcode o);
void jump_and_link_register(cpu& c, opcode o);

void load_byte_signed(cpu& c, opcode o);
void load_byte_unsigned(cpu& c, opcode o);
void load_halfword_signed(cpu& c, opcode o);
void load_halfword_unsigned(cpu& c, opcode o);
void load_upper_immediate(cpu& c, opcode o);
void load_word(cpu& c, opcode o);
void load_word_to_coprocessor(cpu& c, opcode o);
void load_word_left(cpu& c, opcode o);
void load_word_right(cpu& c, opcode o);

void move_from_hi(cpu& c, opcode o);
void move_from_lo(cpu& c, opcode o);

// TODO: Coprocessor stuff

void move_to_hi(cpu& c, opcode o);
void move_to_lo(cpu& c, opcode o);

void multiply_word(cpu& c, opcode o);
void multiply_uword(cpu& c, opcode o);

void nor_reg(cpu& c, opcode o);

void or_reg(cpu& c, opcode o);
void or_imm(cpu& c, opcode o);

void store_byte(cpu& c, opcode o);
void store_halfword(cpu& c, opcode o);
void store_word(cpu& c, opcode o);
void store_word_from_coprocessor(cpu& c, opcode o);
void store_word_left(cpu& c, opcode o);
void store_word_right(cpu& c, opcode o);

void shift_word_left_logical(cpu& c, opcode o);
void shift_word_left_logical_var(cpu& c, opcode o);

void set_on_less_than(cpu& c, opcode o);
void set_on_less_than_imm(cpu& c, opcode o);
void set_on_less_than_imm_unsigned(cpu& c, opcode o);
void set_on_less_than_unsigned(cpu& c, opcode o);

void shift_word_right_arithmetic(cpu& c, opcode o);
void shift_word_right_arithmetic_var(cpu& c, opcode o);
void shift_word_right_logical(cpu& c, opcode o);
void shift_word_right_logical_var(cpu& c, opcode o);

void subtract_word(cpu& c, opcode o);
void subtract_uword(cpu& c, opcode o);

void exclusive_or(cpu& c, opcode o);
void exclusive_or_imm(cpu& c, opcode o);

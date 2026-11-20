// TODO: Exception handling

#include "components/cpu.h"
#include "instructions/instructions.h"

void load_byte(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), data_size::BYTE, data_signedness::SIGNED);
}

void load_byte_unsigned(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), data_size::BYTE, data_signedness::UNSIGNED);
}

void load_halfword_signed(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), data_size::HALF_WORD, data_signedness::SIGNED);
}

void load_halfword_unsigned(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), data_size::HALF_WORD, data_signedness::UNSIGNED);
}

void load_upper_immediate(cpu& c, opcode o)
{
    c.prepare_load_imm(o.immediate() << 16, o.target_reg());
}

void load_word(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load_word(base + offset, o.target_reg());
}

// TODO
void load_word_to_coprocessor(cpu& c, opcode o)
{

}

void load_word_left(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), word_segment::LEFT);
}

void load_word_right(cpu& c, opcode o)
{
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.prepare_load(base + offset, o.target_reg(), word_segment::RIGHT);
}

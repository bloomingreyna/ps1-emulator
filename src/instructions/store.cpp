#include "components/cpu.h"
#include "instructions/instructions.h"

void store_byte(cpu& c, opcode o)
{
    uint8_t target{static_cast<uint8_t>(c.get_gpr(o.target_reg()))};
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.store(base + offset, target, data_size::BYTE);
}

void store_halfword(cpu& c, opcode o)
{
    uint16_t target{static_cast<uint16_t>(c.get_gpr(o.target_reg()))};
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.store(base + offset, target, data_size::HALF_WORD);
}

void store_word(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.store(base + offset, target, data_size::WORD);
}

// TODO
void store_word_from_coprocessor(cpu& c, opcode o)
{

}

void store_word_left(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.store(base + offset, target, word_segment::LEFT);
}

void store_word_right(cpu& c, opcode o)
{
    uint32_t target{c.get_gpr(o.target_reg())};
    uint32_t base{c.get_gpr(o.base_addr())};
    int32_t offset{static_cast<int16_t>(o.offset())};
    c.store(base + offset, target, word_segment::RIGHT);
}

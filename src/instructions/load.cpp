#include "instructions/instructions.h"

void load_byte(cpu& c, opcode o)
{
    int32_t offset{static_cast<int16_t>(o.offset())};
    uint32_t addr{offset + o.base_addr()};
    c.prepare_delayed_load_signed(addr, o.target_reg());
}

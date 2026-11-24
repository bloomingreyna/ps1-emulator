#include "instructions/opcode.h"

uint32_t opcode::op() const { return value >> 26; }
uint32_t opcode::coprocessor() const { return (value & 0x0C000000) >> 26; }
uint32_t opcode::src_reg() const { return (value >> 21) & 0x1F; }
uint32_t opcode::target_reg() const { return (value >> 16) & 0x1F; }
uint32_t opcode::immediate() const { return value & 0xFFFF; }
uint32_t opcode::target_addr() const { return value & 0x3FFFFFF; }
uint32_t opcode::dest_reg() const { return (value >> 11) & 0x1F; }
uint32_t opcode::shift_amt() const { return (value >> 6) & 0x1F; }
uint32_t opcode::function() const { return value & 0x3F; }

uint32_t opcode::base_addr() const { return (value >> 21) & 0x1F; }
uint32_t opcode::offset() const { return value & 0xFFFF; }

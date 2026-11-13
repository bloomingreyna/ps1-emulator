#include "instructions/opcode.h"

uint32_t opcode::op() { return value >> 26; }
uint32_t opcode::src_reg() { return (value >> 21) & 0x1F; }
uint32_t opcode::target_reg() { return (value >> 16) & 0x1F; }
uint32_t opcode::immediate() { return value & 0xFFFF; }
uint32_t opcode::target_addr() { return value & 0x3FFFFFF; }
uint32_t opcode::dest_reg() { return (value >> 11) & 0x1F; }
uint32_t opcode::shift_amt() { return (value >> 6) & 0x1F; }
uint32_t opcode::function() { return value & 0x3F; }

#include "components/cpu.h"

void mult_div_unit::set_hi(uint32_t value) { hi = value; }
void mult_div_unit::set_lo(uint32_t value) { lo = value; }
void mult_div_unit::push_operation(md_operation op) { operation_queue.push(op); }

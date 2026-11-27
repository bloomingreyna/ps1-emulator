#pragma once

#include "components/cpu.h"
#include "utils/cpu_enums.h"

bool add_integer_overflow(uint32_t lhs, uint32_t rhs);
bool sub_integer_overflow(uint32_t lhs, uint32_t rhs);

bool alignment_error(uint32_t addr, data_size alignment, cpu& c);

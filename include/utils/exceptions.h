#pragma once

#include <cstdint>

#include "components/cpu.h"

bool add_integer_overflow(uint32_t lhs, uint32_t rhs);
bool sub_integer_overflow(uint32_t lhs, uint32_t rhs);

bool alignment_error(uint32_t addr, data_size alignment);
bool bus_error(uint32_t addr);

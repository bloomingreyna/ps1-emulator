#include <cassert>
#include <cstdint>

#include "components/cpu.h"
#include "components/mult_div_unit.h"

uint32_t cpu::get_gpr(std::size_t index) const
{
    assert(index < 32);
    if (index == 0) { return 0; }
    return gprs[index];
}

uint32_t cpu::get_pc() const { return pc; }
uint32_t cpu::get_hi() const { return md_unit.get_hi(); }
uint32_t cpu::get_lo() const { return md_unit.get_lo(); }

uint32_t mult_div_unit::get_hi() const { return hi; }
uint32_t mult_div_unit::get_lo() const { return lo; }

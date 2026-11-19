#pragma once

#include <cstdint>

#include "components/cpu.h"

class ps1
{
public:
    uint8_t read_memory(uint32_t addr);
    void write_memory(uint32_t addr, uint8_t value);
private:
    cpu c{};
};

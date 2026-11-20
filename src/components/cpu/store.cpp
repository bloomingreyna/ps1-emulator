#include "components/cpu.h"
#include "components/ps1.h"

void cpu::store(uint32_t addr, uint32_t value, data_size store_size)
{
    unsigned int num_bytes{};
    switch (store_size)
    {
        case data_size::BYTE:
        {
            num_bytes = 1;
            break;
        }
        case data_size::HALF_WORD:
        {
            num_bytes = 2;
            break;
        }
        case data_size::WORD:
        {
            num_bytes = 4;
            break;
        }
    }

    for (unsigned int i{}; i < num_bytes; ++i)
    {
        system.write_memory(addr + i, value >> (8 * i));
    }
}

void cpu::store(uint32_t addr, uint32_t value, word_segment segment)
{
    unsigned int num_bytes{4 - addr % 4};
    switch (segment)
    {
        case word_segment::LEFT:
        {
            for (unsigned int i{}; i < num_bytes; ++i)
            {
                system.write_memory(addr + 3 - i, value >> (24 - (8 * i)));
            }
            break;
        }
        case word_segment::RIGHT:
        {
            for (unsigned int i{}; i < num_bytes; ++i)
            {
                system.write_memory(addr, value >> (8 * i));
            }
            break;
        }
    }
}

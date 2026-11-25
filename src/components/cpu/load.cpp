#include <stdexcept>

#include "components/ps1.h"
#include "components/cpu.h"
#include "utils/cpu_enums.h"
#include "utils/exceptions.h"
#include "utils/sysctlproc_enums.h"

void cpu::finalize_load_operation(uint32_t data, std::size_t index, load_type ltype)
{
    if (!exception_thrown)
    {
        load_vars.trigger_load = true;
        load_vars.intermediate_load_data = data;
        load_vars.intermediate_load_index = index;

        if (ltype == load_type::SPECIAL)
        {
            load_vars.special_load = true;
        }
    }
}

void cpu::prepare_load(uint32_t addr, std::size_t index, data_size load_size, data_signedness signedness)
{
    if (alignment_error(addr, load_size))
    {
        throw_exception(exception_type::ADEL);
        return;
    }

    int32_t data{};
    switch (load_size)
    {
        case data_size::BYTE:
        {
            data = system.read_memory(addr);
            if (signedness == data_signedness::SIGNED)
            {
                data = static_cast<int8_t>(data);
            }
            break;
        }
        case data_size::HALF_WORD:
        {
            data = system.read_memory(addr) | (system.read_memory(addr + 1) << 8);
            if (signedness == data_signedness::SIGNED)
            {
                data = static_cast<int16_t>(data);
            }
            break;
        }
        default: { throw std::invalid_argument("Cannot use data_size::WORD; use dedicated function prepare_load_word instead."); }
    }

    finalize_load_operation(data, index, load_type::REGULAR);
}

void cpu::prepare_load(uint32_t addr, std::size_t index, word_segment segment)
{
    unsigned int num_bytes{4 - addr % 4};
    uint32_t data{};
    switch (segment)
    {
        case word_segment::LEFT:
        {
            if (!load_vars.special_load)
            {
                data = gprs[index];
            }
            else
            {
                data = load_vars.intermediate_load_data;
            }
            data &= static_cast<uint64_t>(0xFFFFFFFF) >> (8 * num_bytes);

            for (unsigned int i{}; i < num_bytes; ++i)
            {
                data |= system.read_memory(addr + 3 - i) << (24 - (8 * i));
            }
            break;
        }
        case word_segment::RIGHT:
        {
            if (!load_vars.special_load)
            {
                data = gprs[index];
            }
            else
            {
                data = load_vars.intermediate_load_data;
            }
            data &= static_cast<uint64_t>(0xFFFFFFFF) << (8 * num_bytes);

            for (unsigned int i{}; i < num_bytes; ++i)
            {
                data |= system.read_memory(addr + i) << (8 * i);
            }
            break;
        }
    }

    finalize_load_operation(data, index, load_type::SPECIAL);
}

void cpu::prepare_load_word(uint32_t addr, std::size_t index)
{
    if (alignment_error(addr, data_size::WORD))
    {
        throw_exception(exception_type::ADEL);
        return;
    }

    uint32_t data{};
    for (int i{}; i < 4; ++i)
    {
        data |= system.read_memory(addr + i) << (8 * i);
    }

    finalize_load_operation(data, index, load_type::REGULAR);
}

void cpu::prepare_load_imm(uint32_t imm, std::size_t index)
{
    finalize_load_operation(imm, index, load_type::REGULAR);
}

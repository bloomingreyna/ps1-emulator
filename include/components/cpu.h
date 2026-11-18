#pragma once

#include <array>
#include <cstdint>

#include "components/cpu_load_vars.h"
#include "components/system_control_processor.h"

enum class data_size
{
    BYTE, HALF_WORD
};

enum class data_signedness
{
    SIGNED, UNSIGNED
};

enum class word_segment
{
    LEFT, RIGHT
};

class opcode;

class cpu
{
public:
    void execute_instruction();

    void load();
    void prepare_load(uint32_t addr, std::size_t index, data_size load_size, data_signedness signedness);
    void prepare_load(uint32_t addr, std::size_t index, word_segment segment);
    void prepare_load(uint32_t addr, std::size_t index);
    void prepare_load_imm(uint32_t value, std::size_t index);

    uint32_t get_gpr(std::size_t index) const;
    uint32_t get_pc() const;
    uint32_t get_hi() const;
    uint32_t get_lo() const;

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);
    void set_hi(uint32_t value);
    void set_lo(uint32_t value);
private:
    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};
    uint32_t hi{};
    uint32_t lo{};

    cpu_load_vars load_vars{};
    system_control_processor sysctlproc{};
};

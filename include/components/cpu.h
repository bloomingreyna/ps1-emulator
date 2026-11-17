#pragma once

#include <array>
#include <cstdint>

#include "components/system_control_processor.h"

class cpu
{
public:
    void execute_instruction();

    void load_signed();
    void load_unsigned();

    void load_delayed();
    void prepare_delayed_load_signed(uint32_t addr, std::size_t index);
    void prepare_delayed_load_unsigned(uint32_t addr, std::size_t index);

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

    system_control_processor sysctlproc{};

    uint32_t load_data_buffer{};
    std::size_t load_index_buffer{};
    bool write_occurred{false};
    std::size_t written_index_priority{};
    bool delay_loading{false};
    bool finish_delay_loading{false};
};

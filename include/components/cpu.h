#pragma once

#include <array>
#include <cstdint>

#include "components/mult_div_unit.h"
#include "components/system_control_processor.h"

class cpu
{
public:
    void execute_instruction();

    void multiply(int64_t lhs, int64_t rhs);
    void multiply(uint64_t lhs, uint64_t rhs);
    void divide(int32_t dividend, int32_t divisor);
    void divide(uint32_t dividend, uint32_t divisor);

    void load_immediately(uint32_t addr, std::size_t index);
    void load_delayed(uint32_t addr, std::size_t index);

    uint32_t get_gpr(std::size_t index) const;
    uint32_t get_pc() const;
    uint32_t get_hi() const;
    uint32_t get_lo() const;

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);
    void set_hi(uint32_t value);
    void set_lo(uint32_t value);
private:
    void load();

    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};

    mult_div_unit md_unit{};
    system_control_processor sysctlproc{};

    uint32_t load_data_buffer{};
    std::size_t load_index_buffer{};
    bool write_occurred{false};
    std::size_t written_index_priority{};
    bool load_mem{false};
    bool delay_load_flag{false};
};

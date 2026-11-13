#pragma once

#include <array>
#include <cstdint>

struct registers
{
    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};
    uint32_t hi{};
    uint32_t lo{};

    // MUL and DIV instructions are asynchronous and multi-cycle; reading hi and lo may return stale data.
    uint32_t hi_fresh{};
    uint32_t lo_fresh{};
};

class cpu
{
public:
    void execute_instruction();

    uint32_t get_gpr(std::size_t index);
    uint32_t get_pc();
    uint32_t get_hi();
    uint32_t get_lo();

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);
    void set_hi(uint32_t value, unsigned int cycle_delay);
    void set_lo(uint32_t value, unsigned int cycle_delay);
private:
    registers cpu_regs{};
};

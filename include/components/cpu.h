#pragma once

#include <array>
#include <cstdint>

struct registers
{
    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};
    uint32_t hi{};
    uint32_t lo{};
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
    void set_hi(uint32_t value);
    void set_lo(uint32_t value);
private:
    registers cpu_regs{};
};

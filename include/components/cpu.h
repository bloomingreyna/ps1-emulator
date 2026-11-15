#pragma once

#include <array>
#include <cstdint>
#include <queue>

struct md_operation
{
    const uint32_t hi;
    const uint32_t lo;
    const unsigned int delay;
};

class cpu;

class mult_div_unit
{
public:
    mult_div_unit(cpu& c_) : c(c_) {};

    void tick();

    void multiply(int64_t lhs, int64_t rhs);
    void multiply(uint64_t lhs, uint64_t rhs);
    void divide(int32_t dividend, int32_t divisor);
    void divide(uint32_t dividend, uint32_t divisor);

    uint32_t get_hi();
    uint32_t get_lo();

    void set_hi(uint32_t value);
    void set_lo(uint32_t value);
    void push_operation(md_operation op);
private:
    cpu& c;
    uint32_t hi{};
    uint32_t lo{};

    std::queue<md_operation> operation_queue{};
    unsigned int op_time_remaining{};
};

class cpu
{
public:
    void execute_instruction();

    uint32_t get_gpr(std::size_t index);
    uint32_t get_pc();

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);

    mult_div_unit md_unit{*this};
private:
    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};
};

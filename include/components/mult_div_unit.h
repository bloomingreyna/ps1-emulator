#pragma once

#include <cstdint>
#include <queue>

struct md_operation
{
    const uint32_t hi;
    const uint32_t lo;
    const unsigned int delay;
};

class mult_div_unit
{
public:
    void tick();

    void multiply(int64_t lhs, int64_t rhs);
    void multiply(uint64_t lhs, uint64_t rhs);
    void divide(int32_t dividend, int32_t divisor);
    void divide(uint32_t dividend, uint32_t divisor);

    uint32_t get_hi() const;
    uint32_t get_lo() const;

    void set_hi(uint32_t value);
    void set_lo(uint32_t value);
private:
    uint32_t hi{};
    uint32_t lo{};

    bool executing{false};
    std::queue<md_operation> operation_queue{};
    unsigned int op_time_remaining{};
};

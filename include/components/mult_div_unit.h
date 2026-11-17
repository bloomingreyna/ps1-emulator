#pragma once

#include <cstdint>
#include <queue>

struct md_operation
{
    const uint32_t hi;
    const uint32_t lo;
    const unsigned int delay;
};

struct mult_div_unit
{
    void tick();

    uint32_t hi{};
    uint32_t lo{};

    bool executing{false};
    std::queue<md_operation> operation_queue{};
    unsigned int op_time_remaining{};
};

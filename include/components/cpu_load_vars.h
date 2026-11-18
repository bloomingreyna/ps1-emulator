#pragma once

#include <cstdint>

struct cpu_load_vars
{
    uint32_t load_data{};
    uint32_t intermediate_load_data{};
    std::size_t load_index{};

    bool special_load{false};
    bool disable_special_load{false};

    bool write_occurred{false};
    std::size_t written_index_priority{};
    bool delay_loading{false};
    bool finish_delay_loading{false};
};

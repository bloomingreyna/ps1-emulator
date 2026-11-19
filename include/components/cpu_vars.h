#pragma once

#include <cstdint>

struct cpu_load_vars
{
    uint32_t load_data{};
    uint32_t intermediate_load_data{};
    std::size_t load_index{};

    bool loading{false};
    bool finish_loading{false};
    bool disable_loading{false};

    bool special_load{false};
    bool disable_special_load{false};

    bool write_occurred{false};
    std::size_t written_index_priority{};
};

struct cpu_pc_change_vars
{
    uint32_t new_pc{};
    bool changing_pc{false};
    bool finish_changing_pc{false};
    bool disable_changing_pc{false};
};

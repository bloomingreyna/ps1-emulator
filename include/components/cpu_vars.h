#pragma once

#include <cstdint>

#include "utils/cpu_enums.h"

struct cpu_load_vars
{
    load_target target{};
    uint32_t target_coprocessor{};
    std::size_t load_index{};

    uint32_t load_data{};

    uint32_t intermediate_load_data{};
    uint32_t intermediate_load_index{};

    bool loading{false};
    bool trigger_load{false};

    bool special_load{false};
    bool disable_special_load{false};

    bool cpu_write_occurred{false};
    bool coprocessor_write_occured{false};
    std::size_t written_index_priority{};
    bool written_coprocessor_priority{};
};

struct cpu_pc_change_vars
{
    uint32_t new_pc{};
    uint32_t intermediate_new_pc{};
    bool changing_pc{false};
};

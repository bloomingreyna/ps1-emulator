#pragma once

enum class data_size
{
    BYTE, HALF_WORD, WORD
};

enum class data_signedness
{
    SIGNED, UNSIGNED
};

enum class word_segment
{
    LEFT, RIGHT
};

enum class load_target
{
    CPU, COPROCESSOR
};

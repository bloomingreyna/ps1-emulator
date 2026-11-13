#include "instructions/instructions.h"
#include "instructions/opcode.h"

void instructions::special_dispatch(cpu& c, opcode o)
{
    switch (static_cast<special_function>(o.function()))
    {
        case special_function::ADD: { instructions::add_word(c, o); break; }
        case special_function::ADDU: { instructions::add_uword(c, o); break; }
        case special_function::AND: { instructions::and_reg(c, o); break; }
    }
}

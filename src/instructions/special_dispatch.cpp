#include "instructions/instructions.h"
#include "instructions/opcode.h"

void special_dispatch(cpu& c, opcode o)
{
    switch (static_cast<special_function>(o.function()))
    {
        case special_function::ADD:
        {
            add_word(c, o);
            break;
        }
        case special_function::ADDU:
        {
            add_uword(c, o);
            break;
        }
        case special_function::AND:
        {
            and_reg(c, o);
            break;
        }
    }
}

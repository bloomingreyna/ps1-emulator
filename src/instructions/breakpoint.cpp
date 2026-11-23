#include "instructions/instructions.h"
#include "utils/sysctlproc_enums.h"

void breakpoint(cpu& c, opcode o)
{
    c.throw_exception(exception_type::BP);
}

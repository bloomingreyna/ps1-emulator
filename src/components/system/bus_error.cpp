#include "components/ps1.h"
#include "utils/sysctlproc_enums.h"

void ps1::throw_bus_error_exception()
{
    if (c.is_executing())
    {
        c.throw_exception(exception_type::DBE);
    }
    else
    {
        c.throw_exception(exception_type::IBE);
    }
}

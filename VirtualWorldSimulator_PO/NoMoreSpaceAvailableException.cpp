#include "NoMoreSpaceAvailableException.h"

const char* NoMoreSpaceAvailableException::what() const
{
    return "No more space available";
}

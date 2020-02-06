#pragma once

#define error(message) assert(!message)

#define assertcheck(expression, message) [result = expression]\
{\
    assert(result && message);\
    return result;\
}()

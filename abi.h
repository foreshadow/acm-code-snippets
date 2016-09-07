#include <cxxabi.h>

template<typename T>
string type(T var)
{
    char result[256];
    unsigned length;
    int size;
    abi::__cxa_demangle(typeid(var).name(), result, &length, &size);
    return result;
}


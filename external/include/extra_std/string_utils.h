#pragma once

#include <string_view>

namespace estd
{
    
template <class ...Args>
std::string format(std::string_view format, Args... args)
{
    constexpr size_t buffSize = 256;
    std::string result(buffSize, '\0');
    const auto size = sprintf_s(result.data(), buffSize, format.data(), std::forward<Args>(args)...);
    result.resize(size);
    return result;
}

}

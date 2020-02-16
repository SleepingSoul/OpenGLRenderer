#pragma once

namespace rdr_impl
{
    class InfoException : public std::exception
    {
    public:
        InfoException(std::string info) : m_info(std::move(info)) {}
        const char* what() const override { return m_info.c_str(); }
    private:
        std::string m_info;
    };
}

#define DeclareInfoException(name)\
class name final : public rdr_impl::InfoException\
{\
public:\
    using Base = rdr_impl::InfoException;\
    using Base::Base;\
}

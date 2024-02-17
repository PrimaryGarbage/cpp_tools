#ifndef PRIM_EXCEPTION_HPP
#define PRIM_EXCEPTION_HPP

#include <string>

#define PRIM_EXCEPTION(what, type) prim::Exception(what, type, __FILE__, __LINE__)

enum class ExceptionType { OperationalException, NotFound };
inline const char* ExceptionType_str[] = { "OperationalException", "NotFound" };

namespace prim
{

    class Exception
    {
    private:
        std::string whatString;
        ExceptionType type;
    public:
        Exception(): whatString("[PRIM EXCEPTION]") {}
        Exception(std::string what, ExceptionType type, std::string file, int line): whatString(std::string("[PRIM EXCEPTION : ") + ExceptionType_str[(u_int32_t)type] + "] -> File: '" + file + "', Line: '" + std::to_string(line) + "', What: '" + what + "'.") {}

        std::string what() const { return whatString; }
        ExceptionType type() const { return type; };
    };

}

#endif // PRIM_EXCEPTION_HPP
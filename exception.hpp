#ifndef PRIM_EXCEPTION_HPP
#define PRIM_EXCEPTION_HPP

#include <string>

#define EXCEPTION(what) prim::Exception(what, __FILE__, __LINE__)
#define EXCEPTION_TYPED(what, type) prim::Exception(what, type, __FILE__, __LINE__)
#define CATCH_IGNORE(code) try{code;}catch(...){}

enum class ExceptionType { OperationalException, NotFound };
inline const char* ExceptionType_str[] = { "OperationalException", "NotFound" };

#define OPERATIONAL ExceptionType::OperationalException
#define NOT_FOUND ExceptionType::NotFound

namespace prim
{

    class Exception
    {
    private:
        std::string whatString;
        ExceptionType type = ExceptionType::OperationalException;
    public:
        Exception(): whatString("[PRIM EXCEPTION]") {}
        Exception(std::string what, std::string file, int line): whatString(std::string("[PRIM EXCEPTION : ") + ExceptionType_str[(u_int32_t)type] + "] -> File: '" + file + "', Line: '" + std::to_string(line) + "', What: '" + what + "'.") {}
        Exception(std::string what, ExceptionType type, std::string file, int line): whatString(std::string("[PRIM EXCEPTION : ") + ExceptionType_str[(u_int32_t)type] + "] -> File: '" + file + "', Line: '" + std::to_string(line) + "', What: '" + what + "'."), type(type) {}

        std::string what() const { return whatString; }
        ExceptionType type() const { return type; };
    };

}

#endif // PRIM_EXCEPTION_HPP
#ifndef __TESTING_HPP__
#define __TESTING_HPP__

#include <string>
#include <iostream>

namespace prim
{
    class TestException
    {
    private:
        std::string message;
    public:
        TestException() : TestException("Test failed.") {}
        TestException(std::string message) : message(message) {}
    
        inline std::string what() const noexcept
        {
            return message;
        }
    };

    class Test
    {
    public:
        inline virtual void setup(){}
        virtual void run() = 0;
    };

    class TestRunner
    {
    private:
        template <class T>
        inline static void pRun(std::enable_if<std::is_base_of<Test, T>::value>::type* = 0)
        {
            T test{};
            test.setup();
            test.run();
        }

        inline static void pRun(...)
        {
            throw TestException("Failed to run the given test class: You can only run classes which are derived from 'prim::Test' class!");
        }

    public:
        template <class T>
        inline static bool run()
        {
            try
            {
                pRun<T>();
                std::cout << "Tests finished succesfully!" << std::endl;
                return true;
            }
            catch(prim::TestException ex)
            {
                std::cout << "Test run failed:\n";
                std::cout << ex.what() << std::endl;
                return false;
            }
        }
    };

    #define ASSERT(expression, message) if(!(expression)) throw prim::TestException(std::string(message) + " >> File: " + __FILE__ + "; Line: " + std::to_string(__LINE__));
}

#endif // __TESTING_HPP__
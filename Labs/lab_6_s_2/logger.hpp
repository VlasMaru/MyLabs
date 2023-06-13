#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>

static auto start = std::chrono::steady_clock::now();

namespace vs
{
    enum class Level_log
    {
        DEBUG,
        RELEASE
    };



    enum class Type_log
    {
        TIMER,
        INFO,
        ERROR
    };



    class Logger
    {
    private:
        static std::ofstream m_out;

        static Level_log m_log_lvl;

        Type_log m_log_tp;

    public:

        explicit Logger(Type_log my_type):m_log_tp(my_type)
        {
            std::cout <<  "Constructor"  << std::endl;
        }

        ~Logger()
        {
            std::cout << "Deconstructor" << std::endl;
        }

        static void SetLogLevel(Level_log level)
        {
            m_log_lvl = level;

        }
        static void SetLogPath(const std::string& log_path)
        {
            m_out.open(log_path);
        }
        

         void Write(const std::string& msg)
        {
             auto end = std::chrono::steady_clock::now();
             std::chrono::duration<double> elapsed_seconds = end - start; 
             double time = elapsed_seconds.count();
             std::string str = msg + " , time ping: " + std::to_string(time);
             switch (m_log_lvl)
             {
             case (vs::Level_log::DEBUG):
                 if (m_log_tp == vs::Type_log::TIMER)
                 {
                     std::cout << "\033[1;36m" << "time ping : " << time << "\033[0m" << std::endl;
                     m_out << str << std::endl;
                 };

                 if (m_log_tp == vs::Type_log::INFO)
                 {
                     std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
                     m_out << str << std::endl;
                 };
                 
                 if (m_log_tp == vs::Type_log::ERROR)
                 {
                     std::cout << "\033[1;31m" << "!ERROR ERROR ERROR ERROR ERROR ERROR!"+ str << "\033[0m" << std::endl;
                     m_out << str + "!ERROR ERROR ERROR ERROR ERROR ERROR!"  <<  std::endl;
                 };
                 break;
             case (vs::Level_log::RELEASE):

                 if (m_log_tp == vs::Type_log::TIMER)
                 {
                     m_out << str << std::endl;
                 };
                 if (m_log_tp == vs::Type_log::INFO)
                 {
                     m_out << str << std::endl;
                 };

                 if (m_log_tp == vs::Type_log::ERROR)
                 {
                     std::cout << "\033[1;31m" << "!ERROR ERROR ERROR ERROR ERROR ERROR!" + str << "\033[0m" << std::endl;
                     m_out << str + "!ERROR ERROR ERROR ERROR ERROR ERROR!" << std::endl;
                 };

             }
        }
    };





}


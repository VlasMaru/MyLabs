#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>
#include "logger.hpp"
#include <thread>


/*Предусмотрите следующие возможности:
1.	Вывод в консоль и в файл
2.	Возможность отключения части логов
3.	Логи разного уровня (Info, Debug, Error и т.п.)
4.	Вывод времени записи лога
*/

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vs::Logger log1(vs::Type_log::TIMER);
    log1.SetLogPath("my_logger.txt");
    log1.SetLogLevel(vs::Level_log::RELEASE);

    log1.Write(" HHHHIII ");
   
}


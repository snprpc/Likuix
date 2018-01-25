#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <time.h>
#include <iostream>
#include <string>


struct TimeStamp
{
    tm* m_create_time;
    tm* m_update_time;

    TimeStamp() {
        time_t now = time(0);
        this->m_create_time = localtime(&now);  //获取当地日期和时间
        this->m_update_time = nullptr;
    }

    void show_tm_stamp(){
        if (this->m_update_time != nullptr) {
            std::cout << "Update Time: "
                 << 1900 + this->m_update_time->tm_year << "y "
                 << this->m_update_time->tm_mon << "mon "
                 << this->m_update_time->tm_mday << "d "
                 <<"W:" <<this->m_update_time->tm_wday <<" "
                 << this->m_update_time->tm_hour << ":"
                 << this->m_update_time->tm_min << std::endl;
        }
        if (this->m_create_time != nullptr) {
            std::cout << "Create Time: "
                << 1900 + this->m_create_time->tm_year << "y "
                << this->m_create_time->tm_mon << "mon "
                << this->m_create_time->tm_mday << "d "
                <<"W:" <<this->m_create_time->tm_wday <<" "
                << this->m_create_time->tm_hour << ":"
                << this->m_create_time->tm_min << std::endl;
        } else {
            std::cout << "NULL TIME STAMP STRUCT !" <<std::endl;
        }

    }
};

class Environment
{
public:
    Environment();
    void setTitle(std::string);
    std::string getTitle();
    void setAuthor(std::string);
    std::string getAuthor();
    void setTmUpdate(time_t);
    TimeStamp getTime();
private:
    std::string m_title;
    std::string m_author;
    TimeStamp m_time;

};

#endif // ENVIRONMENT_H

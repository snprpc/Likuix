#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <time.h>
#include <iostream>
#include <mutex>
#include <memory>
#include <vector>
#include <QDebug>
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

struct StepCmd
{
    std::string m_step_cmd;
    std::string m_step_result;
    static StepCmd* m_stepCmdIns;
};

struct Step
{
    std::string m_step_desc;
    std::vector<StepCmd> m_stepCmdVec;

    static Step* m_stepIns;

    Step(char*& optarg){
        this->m_step_desc = optarg;
    }
    Step(std::string desc, StepCmd cmd) {
        this->m_step_desc = desc;
        this->m_stepCmdVec.push_back(cmd);
    }

    void clean() {
        this->m_step_desc = "";
        this->m_stepCmdVec.clear();
    }

    void show_step(int num) {
        std::cout << "Step" << num << ":" <<std::endl;
        this->m_stepIns != nullptr ? std::cout << "Step desc: " << this->m_stepIns->m_step_desc << std::endl
                                   : std::cout << "Step Desc is not defined." << std::endl ;
        if (this->m_stepCmdVec.size() == 0) {

        }
        for (auto itor = this->m_stepCmdVec.cbegin(); itor != this->m_stepCmdVec.cend(); ++itor) {
            std::cout << "Step Cmd: " << itor->m_step_cmd << std::endl;
            std::cout << "Step Result: " << itor->m_step_result << std::endl;
        }
    }
};

class EnvInstance
{
public:
    static EnvInstance* getEnvIns();
    void setTitle(std::string);
    std::string getTitle();
    void setAuthor(std::string);
    std::string getAuthor();
    void setTmUpdate(time_t);
    TimeStamp getTime();
    void showEnv();
    void showStep();
    void setStep(Step step);
    std::vector<Step> getStep();

private:
    EnvInstance();
    EnvInstance(EnvInstance const&);
    EnvInstance& operator=(EnvInstance const&);
    ~EnvInstance();
    static EnvInstance* m_envinstance;

private:
    std::string m_title;
    std::string m_author;
    TimeStamp m_time;
    std::vector<Step> m_stepVec;

};


#endif // ENVIRONMENT_H

#include "envinstance.h"
EnvInstance* EnvInstance::getEnvIns() {
    std::mutex mt;

    if (m_envinstance == NULL)
    {
        mt.lock();
        if (m_envinstance == NULL)
        {
            m_envinstance = new EnvInstance();
        }
        mt.unlock();
    }

    return m_envinstance;
}
EnvInstance* EnvInstance::m_envinstance = nullptr;


EnvInstance::EnvInstance() {

}
EnvInstance::~EnvInstance() {

}
EnvInstance::EnvInstance(EnvInstance const&) {

}
EnvInstance& EnvInstance::operator=(EnvInstance const&) {

}


void EnvInstance::setTitle(std::string title){
    this->m_title = title;
}
std::string EnvInstance::getTitle(){
    return this->m_title;
}
void EnvInstance::setAuthor(std::string author){
    this->m_author = author;
}
std::string EnvInstance::getAuthor(){
    return this->m_author;
}
void EnvInstance::setTmUpdate(time_t update_time){

    this->m_time.m_update_time = localtime(&update_time);
}
TimeStamp EnvInstance::getTime(){
    return this->m_time;
}
void EnvInstance::setStep(std::string desc, std::string cmd,  std::string result) {
    Step step(desc, cmd, result);
    this->m_stepVec.push_back(step);
}

std::vector<Step> EnvInstance::getStep() {
    return this->m_stepVec;
}

void EnvInstance::showStep() {

    std::vector<Step> stepVec = getStep();
    for (int num = stepVec.size(), i = 1; i <= num; ++i) {
        stepVec[i].show_step(i);
    }
}
void EnvInstance::showEnv() {
    // show title
    if (this->m_title == "") {
        std::cout << "Title is Null." << std::endl;
    } else {
        std::cout << "Title is " << this->m_title << std::endl;
    }
    // show author
    if (this->m_author == "") {
        std::cout << "Author is Null." << std::endl;
    } else {
        std::cout << "Author is " << this->m_author << std::endl;
    }
    // show timestamp
    this->getTime().show_tm_stamp();

    //show step


}

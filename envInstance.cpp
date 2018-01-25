#include "environment.h"

Environment::Environment()
{

}

void Environment::setTitle(std::string title){
    this->m_title = title;
}
std::string Environment::getTitle(){
    return this->m_title;
}
void Environment::setAuthor(std::string author){
    this->m_author = author;
}
std::string Environment::getAuthor(){
    return this->m_author;
}
void Environment::setTmUpdate(time_t update_time){

    this->m_time.m_update_time = localtime(&update_time);
}
TimeStamp Environment::getTime(){
    return this->m_time;
}

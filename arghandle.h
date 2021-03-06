#ifndef ARGHANDLE_H
#define ARGHANDLE_H
#include <iostream>
#include <unistd.h>
#include <envinstance.h>
#include <QDebug>
class ArgHandle
{
public:
    ArgHandle(int argc, char** argv);
    void show_args();
    void deal_args();

    void t_handle();
    void a_handle();
    void s_handle();
    void none_handle();

    void getopt_debug();
    int setOpt(int opt);

private:
    int m_opt;
    int m_argc;
    char** m_argv;
};

#endif // ARGHANDLE_H

#include <QCoreApplication>
#include <iostream>
#include <unistd.h>

#include "environment.h"
#include "arghandle.h"


int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    Environment env;
    env.getTime().show_tm_stamp();

    ArgHandle a_handle(argc, argv);
    //a_handle.show_args();

    while(a_handle.setOpt(getopt(argc, argv, "t:")) != -1) {
        a_handle.deal_args();
    }

    return 0;
}

#include <iostream>
#include <unistd.h>

#include "envinstance.h"
#include "arghandle.h"
#include <QDebug>

int main(int argc, char* argv[])
{
    ArgHandle a_handle(argc, argv);

    while(a_handle.setOpt(getopt(argc, argv, "t:a:s:c:r")) != -1) {
        a_handle.deal_args();
    }

    return 0;
}

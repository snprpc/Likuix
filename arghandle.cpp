#include "arghandle.h"

ArgHandle::ArgHandle(int argc, char **argv) {
    this->m_argc = argc;
    this->m_argv = argv;
}

void ArgHandle::show_args() {
        for (int i = 0; i < this->m_argc; ++i) {
            std::cout << this->m_argv[i] << std::endl;
        }
}

int ArgHandle::setOpt(int opt) {
    this->m_opt = opt;
    return this->m_opt;
}

void ArgHandle::deal_args() {
    switch(this->m_opt) {
        case 't':
            t_handle();
            break;

        case '?':
            none_handle();
            break;
    }
}
void ArgHandle::t_handle() {
    getopt_debug();

}

void ArgHandle::none_handle() {
    getopt_debug();
}

void ArgHandle::getopt_debug() {
    std::cout << "opt:" << (char)this->m_opt << std::endl;

    optopt != 0 ? std::cout << "optopt: " << optopt << std::endl
                               : std::cout << "optopt is 0" << std::endl;
    optarg != nullptr ? std::cout << "argument: " << optarg << std::endl\
                                     : std::cout << "argument is null" << std::endl;
    std::cout << "optind: " << optind << std::endl;
}




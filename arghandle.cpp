#include "arghandle.h"

ArgHandle::ArgHandle(int argc, char **argv) {
    this->m_argc = argc;
    this->m_argv = argv;
    EnvInstance::getEnvIns()->setTmUpdate(time(0));
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
        case 'a':
            a_handle();
            break;
        case 's':
            s_handle();
            break;
        case '?':
            none_handle();
            break;
    }
}
void ArgHandle::t_handle() {
    // this->getopt_debug();
    qDebug("T_handle Output: ");
    EnvInstance::getEnvIns()->setTitle(optarg);
    // EnvInstance::getEnvIns()->showEnv();
}

void ArgHandle::a_handle() {
    // this->getopt_debug();
    qDebug("A_handle Output: ");
    EnvInstance::getEnvIns()->setAuthor(optarg);
    EnvInstance::getEnvIns()->showEnv();
}

void ArgHandle::s_handle() {
    this->getopt_debug();
    qDebug("S_handle Output: ");
    // get step desc
    std::string desc = optarg;
    // get step cmd
    std::string cmd = " ";
    // get step result
    std::string result = " ";
    EnvInstance::getEnvIns()->setStep(desc, cmd, result);
    EnvInstance::getEnvIns()->showEnv();

}
void ArgHandle::none_handle() {
    qDebug("None_Handle: ");
}

void ArgHandle::getopt_debug() {
    qDebug("opt: %c", (char)this->m_opt);
    optopt != 0 ? qDebug("optopt: %i", optopt)
                               : qDebug("Optopt Is Zero.");
    optarg != nullptr ? qDebug("argument: %s", optarg)
                                     :qDebug("Argument Is Null");
    qDebug("optind: %i", optind);
}

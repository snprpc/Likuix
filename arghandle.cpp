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
        case 'r':
        case 'c':
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


    switch (this->m_opt) {
        case 's':
            // get step desc
            qDebug("S_handle Output: ");
            // this->getopt_debug();
            if (Step::m_stepIns == nullptr) {
                Step::m_stepIns = new Step(optarg);
            } else {
                EnvInstance::getEnvIns()->setStep(*Step::m_stepIns);
                Step::m_stepIns->clean();
                Step::m_stepIns->m_step_desc = optarg;
            }
            break;
        case 'c':
            if (Step::m_stepIns == nullptr) {
                std::cout << "Please Input Command Description First:(use -s)" << std::endl;
                break;
            }
            qDebug("C_handle Output: ");
            // this->getopt_debug();
            if (StepCmd::m_stepCmdIns == nullptr) {
                StepCmd::m_stepCmdIns = new StepCmd();
            }
            StepCmd::m_stepCmdIns->m_step_cmd = optarg;
            Step::m_stepIns->m_stepCmdVec.push_back(*StepCmd::m_stepCmdIns);
            EnvInstance::getEnvIns()->setStep(*Step::m_stepIns);
            EnvInstance::getEnvIns()->showEnv();
            break;
        case 'r':
            qDebug("R_handle Output: ");
            break;
    }
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

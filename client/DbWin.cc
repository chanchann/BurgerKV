#include "DbWin.h"
#include "common/ErrorCode.h"
#include "Cmd.h"
#include <iostream>
#include <burger/base/StringUtil.h>

using namespace burgerkv;

void DbWin::start() {
    // todo: here imitate mongodb
    std::cout << "Welcome to BurgerKB Shell" << std::endl;
    std::cout << "help for help, Ctrl+c or quit to exits" << std::endl;
    quit_ = false;
    while(!quit_) {
        prompt();
    } 
}

void DbWin::prompt() {
    int ret = ErrorCode::OK;
    ret = inputBuf_.readInput();
    if(ret) {
        // todo: log error code info
        return;
    }
    std::string inputCmd = inputBuf_.retriveAsString();
    std::vector<std::string> cmdVec;
    // split the input sentence 
    burger::StringUtil::split(inputCmd, cmdVec);
    
    std::string cmd;
    std::vector<std::string> paramVec;
    int cnt = 0;
    for(auto it = cmdVec.begin(); it != cmdVec.end(); it++) {
        if(cnt == 0) {
            cmd = *it;
            cnt++;
        } else {
            paramVec.emplace_back(*it);
        }
    }
    // ICmd* pCmd = nullptr;
    // pCmd = cmdFactory_.getCmdProc(cmd);
    // if(pCmd != nullptr) {
    //     pCmd->execute(paramVec);
    // }
}


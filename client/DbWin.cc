#include "DbWin.h"
#include "common/ErrorCode.h"
#include <iostream>

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
    // inputBuf_.
}


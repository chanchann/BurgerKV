#ifndef DBWIN_H
#define DBWIN_H

#include <string>
#include <vector>
#include "CmdFactory.h"
#include "InputBuffer.h"

namespace burgerkv {

class DbWin {
public:
    DbWin() = default;
    ~DbWin() = default;

    void start();
    void prompt();
private:   
    // CmdFactory cmdFactory_;
    bool quit_ = true;
    InputBuffer inputBuf_;
};

} // namespace burgerkv

#endif // DBWIN_H
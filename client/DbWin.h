#ifndef DBWIN_H
#define DBWIN_H

#include <string>

const int CMD_BUFFER_SIZE = 512;

class DbWin {
public:
    DbWin() = default;
    ~DbWin() = default;

    void start();
    void prompt();
    void split(const std::string& text, char delim, std::vector<std::string>& result);
    char* readLine(char *p, int length);
    int readInput(const char *pPromt, int numIndent);
private:   
    CmdFactory cmdFactory_;
    char cmdBuffer_[CMD_BUFFER_SIZE];
  
};


#endif // DBWIN_H
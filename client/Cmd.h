#ifndef CMD_H
#define CMD_H

#include <functional>

#define RECV_BUF_SIZE 4096
#define SEND_BUF_SIZE 4096


class ICmd {
    // todo: param need fix
    using OnMsgBuildCb = std::function<int (char** ppBuffer, int *pBufSize, bson::BSONObj &obj);
public:
    // todo: param need fix
    virtual int execute(ossSocket& sock, std::vector<std::string>& argVec);
    int getError(int code);
    int recvReply(ossSocket& sock);
    int sendOrder(ossSocket& sock, OnMsgBuildCb& onMsgBuild);
    int sendOrder(ossSocket& sock, int opCode);
    virtual int handleReply() { return BKV_OK; }
private:   
    char recvBuf_[RECV_BUF_SIZE];
    char sendBuf_[SEND_BUF_SIZE];
    std::string jsonStr_;
};

class ConnectCommand : public ICommand {
public:
    int execute(ossSocket & sock, std::vector<std::string>& argVec ) override;
private:
    std::string address_;
    int port_;
};

class QuitCommand : public ICommand {
public:
    int execute(ossSocket& sock, std::vector<std::string>& argVec) override;
protected:
    int handleReply();
};

class HelpCommand : public ICommand {
public:
    int execute(ossSocket& sock, std::vector<std::string>& argVec) override;
};



#endif // CMD_H
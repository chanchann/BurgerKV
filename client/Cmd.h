#ifndef CMD_H
#define CMD_H

#include <functional>
#include <vector>
#include <string>

#define RECV_BUF_SIZE 4096
#define SEND_BUF_SIZE 4096

namespace burgerkv {

class ICmd {
    using OnMsgBuildCb = std::function<int (char** ppBuffer, int *pBufSize, bson::BSONObj &obj);
public:
    virtual int execute(const std::vector<std::string>& argVec);
    int getError(int code);
    int recvReply();
    int sendOrder(OnMsgBuildCb& onMsgBuild);
    int sendOrder(int opCode);
    virtual int handleReply() { return BKV_OK; }
private:   
    char recvBuf_[RECV_BUF_SIZE];
    char sendBuf_[SEND_BUF_SIZE];
    std::string jsonStr_;
};

class ConnectCmd : public ICmd {
public:
    int execute(std::vector<std::string>& argVec) override;
private:
    std::string address_;
    int port_;
};

class QuitCmd : public ICmd {
public:
    int execute(std::vector<std::string>& argVec) override;
protected:
    int handleReply();
};

class HelpCmd : public ICmd {
public:
    int execute(std::vector<std::string>& argVec) override;
};

} // namespace burgerkv 

#endif // CMD_H
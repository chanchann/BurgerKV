#include "Cmd.h"
#include "common/ErrorCode.h"
using namespace burgerkv;

int ICmd::execute(const std::vector<std::string>& argVec) {
    return ErrorCode::OK;
}



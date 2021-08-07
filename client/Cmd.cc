#include "Cmd.h"
#include "common/ErrorCode.h"
#include <burger/base/Log.h>
using namespace burgerkv;

int ICmd::execute(const std::vector<std::string>& argVec) {
    return ErrorCode::OK;
}

void ICmd::logError(ErrorCode code) 
{
    switch(code) {
        case ErrorCode::OK: 
            break;
        case ErrorCode::IO:   
            ERROR("io erro is occurred");
            break;
        // ...
        default:
            break;
    }
}



#include "InputBuffer.h"
#include "common/ErrorCode.h"
#include <burger/base/StringUtil.h>
#include <cstring>

namespace {
    const char kSpace = ' ';
    const char kTab = '\t';
    const char kBackSlant = '\\';
    const char kNewLine = '\n';
}

using namespace burgerkv;

const size_t InputBuffer::kInitialSize;

InputBuffer::InputBuffer(size_t initialSize) 
    : buffer_(initialSize) {
}

int InputBuffer::readInput() {
    index_ = 0;
    std::cout << "burgerkv > ";
    while(!readLine()) {  // 如果是 \ 则还没结束
        std::cout << std::endl;
        std::cout << "> ";
    }
    return ErrorCode::OK;
}

std::string InputBuffer::retriveAsString() {
    std::string result(&*buffer_.begin(), index_);
    index_ = 0;
    return result;
}

// todo : more elegant here?
bool InputBuffer::readLine() {
    char ch;
    bool isEnd = true;
    while((ch = static_cast<char>(std::getchar())) != kNewLine) {
        switch(ch) {
            case kBackSlant:  
                buffer_.push_back(kSpace);
                index_++;
                isEnd = false;
                break;
            case kTab:       
                buffer_.push_back(kSpace);
                index_++;
                break;
            default:
                buffer_.push_back(ch);
                index_++;
        }
        if(!isEnd) return false;
    }
    return true;
} 

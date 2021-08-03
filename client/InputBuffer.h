#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <string>
#include <vector>
#include <iostream>

namespace burgerkv {

class InputBuffer {
public:
    static const size_t kInitialSize = 512;  // todo : why static const here? see muduo
    InputBuffer(size_t initialSize = kInitialSize); 
    ~InputBuffer() = default;

    int readInput();
    std::string retriveAsString();
    // void split(const std::string& text, char delim, std::vector<std::string>& result);
private:
    bool readLine();
    // std::vector<std::string> processInput();
private:  
    std::vector<char> buffer_;
    size_t index_;
};

} // namespace burgerkv 

#endif // INPUTBUFFER_H
#ifndef ERRORCODE_H
#define ERRORCODE_H

// todo : #define error code 还是选择 enum 还是 enum class
// https://akrzemi1.wordpress.com/2017/09/04/using-error-codes-effectively/
// todo : use more modern way !!


namespace burgerkv {
    
enum ErrorCode {
    // error code list
    OK = 0,
    IO = -1,
    INVALIDARG = -2,
    PERM = -3,
    OOM = -4,
    SYS = -5,
    PMD_HELP_ONLY = -6,
    PMD_FORCE_SYSTEM_EDU = -7,
    TIMEOUT = -8,
    QUIESCED = -9,
    EDU_INVAL_STATUS = -10,
    NETWORK = -11,
    NETWORK_CLOSE = -12,
    APP_FORCED = -13,
    IXM_ID_EXIST = -14,
    HEADER_INVALID = -15,
    IXM_ID_NOT_EXIST = -16,
    NO_ID = -17
};

} // namesapce burgerkv


#endif // ERRORCODE_H
#ifndef DBSTATUS_H
#define DBSTATUS_H

// todo : use define is better here 
// todo e.g.
// #define BKV_OK 0
// #define BKV_IO -1

enum class DBStatus {
    BKV_OK,
    BKV_IO,    
    
};


#endif // DBSTATUS_H
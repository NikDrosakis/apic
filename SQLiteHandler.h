#ifndef SQLITE_HANDLER_H
#define SQLITE_HANDLER_H

#include "sqlite/sqlite3.h"
#include <iostream>
#include <string>
using namespace Pistache;


class SQLiteHandler {
public:
    SQLiteHandler(const char* dbName);
    ~SQLiteHandler();

    int openDatabase();
    void closeDatabase();
    int insertData(const char* tableName, const char* values);
    std::string fetchData(const char* tableName);

private:
    sqlite3* db;
    const char* dbName;
};

#endif // SQLITE_HANDLER_H

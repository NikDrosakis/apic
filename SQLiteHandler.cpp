#include "SQLiteHandler.h"
#include <string>
#include <iostream>

SQLiteHandler::SQLiteHandler(const char* dbName) : dbName(dbName), db(nullptr) {
}

SQLiteHandler::~SQLiteHandler() {
    closeDatabase();
}

int SQLiteHandler::openDatabase() {
    return sqlite3_open(dbName, &db);
}

void SQLiteHandler::closeDatabase() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

int SQLiteHandler::insertData(const char* tableName, const char* values) {
    // Construct the insert query
    std::string insertQuery = "INSERT INTO " + std::string(tableName) + " VALUES (" + std::string(values) + ");";

    // Execute the insert query
    return sqlite3_exec(db, insertQuery.c_str(), nullptr, nullptr, nullptr);
}

std::string SQLiteHandler::fetchData(const char* tableName, std::string& resultData) {
    // Construct the select query
    std::string selectQuery = "SELECT * FROM " + std::string(tableName) + ";";

    // String to hold the fetched data
    auto callback = [](void* data, int columns, char** values, char** columnNames) -> int {
        for (int i = 0; i < columns; ++i) {
            std::cout << columnNames[i] << ": " << (values[i] ? values[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
        return 0;
    };

    // Execute the select query
    int resultCode = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, nullptr);
    if (resultCode != SQLITE_OK) {
        // Failed to fetch data, set resultData to an error message
        resultData = "Failed to retrieve data.";
    } else {
        // Successfully fetched data, set resultData to an appropriate message or leave it empty
        resultData = "Data retrieved successfully.";
    }
    return resultCode;
}


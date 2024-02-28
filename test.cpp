#include <iostream>
#include <sqlite3.h>

using namespace std;

int main() {
    // Pointer to SQLite connection
    sqlite3* db;

    // Save the connection result
    int exit = 0;
    exit = sqlite3_open("main.sqlite", &db);

    // Sample Fetch (Select) Query
    const char* selectQuery = "SELECT * FROM questions;";

    // Callback function for each row of the result
    auto callback = [](void* data, int columns, char** values, char** columnNames) -> int {
        for (int i = 0; i < columns; ++i) {
            cout << columnNames[i] << ": " << (values[i] ? values[i] : "NULL") << "\t";
        }
        cout << endl;
        return 0;
    };

    // Execute the select query
    exit = sqlite3_exec(db, selectQuery, callback, nullptr, nullptr);

    // Test if there was an error
    if (exit != SQLITE_OK) {
        cout << "Select Error: " << sqlite3_errmsg(db) << endl;
    }

    // Close the connection
    sqlite3_close(db);

    return 0;
}

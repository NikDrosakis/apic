#include <pistache/endpoint.h>
#include "SQLiteHandler.cpp"
#include <iostream>
using namespace Pistache;

class FetchQuestionsHandler : public Http::Handler {
public:
    HTTP_PROTOTYPE(FetchQuestionsHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override {
        // Implement your handling logic here
        // For example, you can call SQLiteHandler's fetchData method and respond with the data
        SQLiteHandler dbHandler("main.sqlite");

        int result = dbHandler.openDatabase();
        if (result != SQLITE_OK) {
            response.send(Http::Code::Internal_Server_Error, "Error opening SQLite database");
            return;
        }

        // Fetch data and send the response
        std::string data = dbHandler.fetchData("questions");
        response.send(Http::Code::Ok, data);

        // Close the database
        dbHandler.closeDatabase();
    }
};

int main()
{
    Pistache::Http::Endpoint server(Pistache::Address(Pistache::Ipv4::any(), Pistache::Port(9080)));
    auto handler = std::make_shared<FetchQuestionsHandler>();
    server.setHandler(handler);
    server.serve();
    return 0;
}
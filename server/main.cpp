#include "Server.h"

int main() {
    Server server("127.0.0.1", 54000);
    if (server.init() != 0) {
        server.run();
    }
}
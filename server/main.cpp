#include "Server.h"

int main() {
    Server server;
    if (server.init() != 0) {
        server.run();
    }
}
#include "queue_1.1.h"

int main() {
    std::cout << "commands:" << std::endl;
    std::cout << "insert - insert element in queue" << std::endl;
    std::cout << "delete - delete max element of queue" << std::endl;
    std::cout << "dump - print queue" << std::endl;
    std::cout << "stop - exit" << std::endl;
    queue queue;
    while(1) {
        std::cout << std::endl;
        string command = " ";
        std::cin >> command;
        if(command.compare("stop") == 0) {
            return 0;
        } else if(command.compare("insert") == 0) {
            std::cout << "enter element's priority";
            std::cout << std::endl;
            int priority;
            std::cin >> priority;
            std::cout << "enter element's value";
            std::cout << std::endl;
            data value;
            std::cin >> value;
            queue.queue_insert(priority, value);
        } else if(command.compare("delete") == 0) {
            queue.queue_max_delete();
        } else if(command.compare("dump") == 0) {
            queue.queue_dump();
        } else {
            std::cout << "unknow command";
        }
    }
}

using namespace std;

#include <iostream>
#include <string>

#define TURN_SIZE 3
typedef int data;

struct Queue_type {
    int priority;
    data value;
};


class queue {                                                                                            //implementation
    private:
        Queue_type mas_queue [TURN_SIZE];             // array, which is implemented on the basis of all
        int mas_size;                                 // the current size of the queue
        int mas_regulation(int num);                  // function, which orders all                              +
    public:
        queue();
        void queue_insert(int priority, data value);  // add an item                                             +
        void queue_max_delete();                      // remove the element with the highest priority            +
        void queue_dump () const;                     // print queue                                             +
        bool queue_is_empty () const;                 // determines whether the elements in the queue            +
};

queue::queue() {
    mas_size = 0;
    for(int i = 0; i < TURN_SIZE; i++) {
        mas_queue[i] = {0, 0};
    }
}

void queue::queue_insert(int priority, data value) {
    Queue_type cur = {priority, value};
    int number_in_mas_cur = mas_size;
    mas_queue[number_in_mas_cur] = cur;
    mas_size++;
    while(1) {
        if(mas_size == 0) {
            break;
        } else if(cur.priority > mas_queue[(number_in_mas_cur - 1)/2].priority) {
            Queue_type bubble = {cur.priority, cur.value};
            mas_queue[number_in_mas_cur] = mas_queue[(number_in_mas_cur - 1)/2];
            mas_queue[(number_in_mas_cur - 1)/2] = bubble;
            number_in_mas_cur = (number_in_mas_cur - 1)/2;
        } else {
            break;
        }
    }
}

void queue::queue_dump() const {
    std::cout << "priority";
    for(int i = 0; i < mas_size; i++) {
        std::cout << " - " << "  " << mas_queue[i].priority;
    }
    std::cout <<  std::endl;
    std::cout << "value   ";
    for(int i = 0; i < mas_size; i++) {
        std::cout << " - " << mas_queue[i].value;
    }
    std::cout <<  std::endl;
}

void queue::queue_max_delete() {
    if(queue_is_empty() == 1) {

    } else {
        mas_queue[0] = mas_queue[mas_size - 1];
        mas_size--;
        mas_regulation(0);
    }
}

int queue::mas_regulation(int num) {
    Queue_type bubble = {0, 0};
    if((2 * num + 1) >= mas_size){
    } else if(mas_queue[num].priority < mas_queue[2 * num + 1].priority) {
        bubble = mas_queue[num];
        mas_queue[num] = mas_queue[2 * num + 1];
        mas_queue[2 * num + 1] = bubble;
        mas_regulation(2 * num + 1);
    } else if(mas_queue[num].priority >= mas_queue[2 * num + 1].priority){
        mas_regulation(2 * num + 1);
    }
    bubble = {0, 0};
    if((2 * num + 2) >= mas_size){
    } else if(mas_queue[num].priority < mas_queue[2 * num + 2].priority) {
        bubble = mas_queue[num];
        mas_queue[num] = mas_queue[2 * num + 2];
        mas_queue[2 * num + 2] = bubble;
        mas_regulation(2 * num + 2);
    } else if(mas_queue[num].priority >= mas_queue[2 * num + 2].priority){
        mas_regulation(2 * num + 2);
    }
    return 0;
}

bool queue::queue_is_empty () const {
    if(mas_size == 0) {
        return 1;
    } else {
        return 0;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------

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

#include <iostream>

#define TURN_SIZE 100
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
        bool queue_is_empty () const;                 // determines whether the elements in the queue            -
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
    mas_queue[0] = mas_queue[mas_size - 1];
    mas_size--;
    mas_regulation(0);
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

//------------------------------------------------------------------------------------------------------------------------------------

int main() {
    queue queue;
    queue.queue_dump();
    queue.queue_insert(4,101);
    queue.queue_insert(2,111);
    queue.queue_insert(7,122);
    queue.queue_insert(1,134);
    queue.queue_insert(3,124);
    queue.queue_insert(5,153);
    queue.queue_insert(9,172);
    queue.queue_insert(8,112);
    queue.queue_insert(6,185);
    queue.queue_dump();
    queue.queue_max_delete();
    queue.queue_dump();
    queue.queue_max_delete();
    queue.queue_dump();
    queue.queue_max_delete();
    queue.queue_dump();
    queue.queue_max_delete();
    queue.queue_dump();
    return 0;
}


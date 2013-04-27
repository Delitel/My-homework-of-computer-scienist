#include "queue_2.0.h"

queue::queue() {
    mas_size = 0;
    mas_queue = new Queue_type[1];
    mas_queue[0] = {0, 0};
}

void queue::queue_insert(int priority, data value) {
    Queue_type cur = {priority, value};
    int number_in_mas_cur = mas_size;
    if(mas_size == 0) {
        mas_queue[0] = cur;
        mas_size++;
    } else {
        Queue_type* mas_copy = new Queue_type[mas_size];
        for(int i = 0; i < mas_size; i++) {
            mas_copy[i] = mas_queue[i];
        }
        mas_queue = new Queue_type[mas_size + 1];
        for(int i = 0; i < mas_size; i++) {
            mas_queue[i] = mas_copy[i];
        }
        mas_queue[mas_size] = cur;
        mas_size++;
        delete[] mas_copy;
    }
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
        std::cout << " - " << setw(5) << mas_queue[i].priority;
    }
    std::cout <<  std::endl;
    std::cout << "value   ";
    for(int i = 0; i < mas_size; i++) {
        std::cout << " - " << setw(5) << mas_queue[i].value;
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

int main() {
    return 0;
}

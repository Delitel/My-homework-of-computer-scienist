#include <iostream>

#define TURN_SIZE 100
typedef int data;

struct Turn_type {
    int priority;
    data value;
};

class turn {
    private:
        Turn_type mas_turn [TURN_SIZE];              // array, which is implemented on the basis of all
        int mas_size;                                // the current size of the queue
        void mas_regulation();                       // function, which orders all
    public:
        turn();
        ~turn();
        void turn_insert(int priority, data value);  // add an item
        void turn_max_delete();                      // remove the element with the highest priority
        void turn_dump () const;                     // print queue
        bool turn_is_empty () const;                 // determines whether the elements in the queue
};

turn::turn() {
    mas_size = 0;
    for(int i = 0; i < TURN_SIZE; i++) {
        mas_turn[i] = {0, 0};
    }
}

turn::~turn() {

}


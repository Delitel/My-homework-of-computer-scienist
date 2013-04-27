#ifndef queue_2.0_h
#define queue_2.0_h
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef int data;

struct Queue_type {
    int priority;
    data value;
};


class queue {                                                                                            //implementation
    private:
        Queue_type* mas_queue;                        // pointer on first array's element
        int mas_size;                                 // the current size of the queue
        int mas_regulation(int num);                  // function, which orders all                              +
    public:
        queue();
        void queue_insert(int priority, data value);  // add an item                                             +
        void queue_max_delete();                      // remove the element with the highest priority            +
        void queue_dump () const;                     // print queue                                             +
        bool queue_is_empty () const;                 // determines whether the elements in the queue            +
};

#endif

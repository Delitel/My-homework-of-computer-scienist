#include <iostream>

#define TURN_SIZE 100

struct Turn_type {
    int priority;
    data value;
}

class turn {
    private:
        Turn_type mas_turn [TURN_SIZE];              // массив, на основе которого реализуется очередь
        int mas_size;                                // текущий размер очереди
        void mas_regulation();                       // функция, упорядочивающая очередь
    public:
        turn();                                      // конструктор
        ~turn();                                     // деструктор
        void turn_insert(int priority, data value);  // добавить элемент
        void turn_max_delete();                      // удалить элемент с максимальным приоритетом
        void turn_dump();                            // распечатка очереди
        bool turn_is_empty();                        // определяет, есть ли в очереди элементы
};

turn::turn() {
    mas_size = 0;
    for(int i = 0; i < TURN_SIZE; i++) {
        mas_turn[i] = 0;
    }
}

turn::~turn() {

}


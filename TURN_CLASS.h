#include <iostream>

#define TURN_SIZE 100

struct Turn_type {
    int priority;
    data value;
}

class turn {
    private:
        Turn_type mas_turn [TURN_SIZE];              // ������, �� ������ �������� ����������� �������
        int mas_size;                                // ������� ������ �������
        void mas_regulation();                       // �������, ��������������� �������
    public:
        turn();                                      // �����������
        ~turn();                                     // ����������
        void turn_insert(int priority, data value);  // �������� �������
        void turn_max_delete();                      // ������� ������� � ������������ �����������
        void turn_dump();                            // ���������� �������
        bool turn_is_empty();                        // ����������, ���� �� � ������� ��������
};

turn::turn() {
    mas_size = 0;
    for(int i = 0; i < TURN_SIZE; i++) {
        mas_turn[i] = 0;
    }
}

turn::~turn() {

}


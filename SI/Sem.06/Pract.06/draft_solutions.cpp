#include <iostream>

int count_bit_ones(int number);
int switch_last_bit_one(int number);
int find_last_k_bits_number(int number, int last_k_bits);
bool is_second_number_bits_part_of_first_number(int first_number, int second_number);
int single_number(const int* arr, int size);

int main() {
    int arr[] = { 9, 18, 9, 12, 18, 15, 12 };
    std::cout << single_number(arr, 7);


//    std::bitset<32> first(13);
//    std::cout << "Binary: " << first << std::endl;
//    std::bitset<32> x(7);
//    std::cout << "Binary: " << x << std::endl;
//
//    std::cout << is_second_number_bits_part_of_first_number(13, 7);

    return 0;
}

// Task 02
//Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.
//
//Вход: 189
//Изход: 6
int count_bit_ones(int number) {
    const int one_bit = 1;
    int count = 0;
    while (number > 0) {
        if ((number & one_bit) == 1) {
            count++;
        }

        number = number >> 1;
    }

    return count;
}

// Task 03
//Напишете функция, която приема цяло число и обръща най-десният бит в него, който е единица.
//
//Вход: 12 | Изход: 8
//Вход: 15 | Изход: 14
int switch_last_bit_one(int number) {
    int bit_mask = 1;
    int last_bit_position_offset = 0;
    int temp = number;

    while ((number & bit_mask) != bit_mask && number > 0) {
        last_bit_position_offset++;
        number = number >> 1;
    }
    bit_mask = bit_mask << last_bit_position_offset;
    return temp ^ bit_mask;
}

// Task 04
//Напишете функция, която по подадено цяло число n и цяло число k и връща числото, което е "закодирано" в последните k бита на n.
//
//Вход: 15 2 | Изход: 3
//Вход: 189 3 | Изход: 5
//Вход: 189 4 | Изход: 13
int find_last_k_bits_number(int number, int last_k_bits) {
    const int bit_one = 1;
    int bit_mask = 0;
    while (last_k_bits > 0) {
        bit_mask = bit_mask << 1;
        bit_mask = bit_mask | bit_one;
        last_k_bits--;
    }

    return number & bit_mask;
}

// Task 05
//Напишете функция, която приема цяло число n и цяло число k и връща дали k в двоичен запис (разглеждайки го без водещите 0-ли) е част от двоичния запис на n.
//
//Вход: 15 3 | Изход: true
//Вход: 13 5 | Изход: true
//Вход: 13 7 | Изход: false
bool is_second_number_bits_part_of_first_number(int first_number, int second_number) {
    return (first_number & second_number) == second_number;
}

// task 07
//Да се напише функция, която приема масив, в който всяко число се среща 2 пъти с изключение на едно число, което се среща веднъж.
//Напишете функция, която приема такъв масив и връща кое е това число.
//(Подсказка: използвайте побитови операции, за да постигнете линейно решение)
//
//Вход: 9 18 9 12 18 15 12
//Изход: 15
int single_number(const int* arr, int size) {
    int number = 0;
    for (int i = 0; i < size; i++) {
        number ^= arr[i];
    }

    return number;
}


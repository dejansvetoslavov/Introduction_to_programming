#include <iostream>

int main() {
    int number = 0;
    std::cout << "Enter number: ";
    std::cin >> number;

    int targetBase = 0;
    std::cout << "Enter base: ";
    std::cin >> targetBase;

    int temp = number;
    char buffer[100];
    int index = 0;
    char allowedChars[] = { '0', '1', '2', '3', '4', '5',  '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    while (temp > 0) {
        int remainder = temp % targetBase;
        buffer[index++] = allowedChars[remainder];
        temp /= targetBase;
    }
    index--;
    while (index > -1) {
        std::cout << buffer[index--];
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <cmath>

int charToNumber(char c);

int main() {
    int n = 2;
    int base = 16;
    int sum = 0;
    char* input = "7E";

    for (int i = 0; i < n; i++) {
        char current = input[n - i - 1];
        int digit = charToNumber(current);
        sum += digit * pow(base, i);
    }

    std::cout << sum << std::endl;
    return 0;
}

int charToNumber(char c) {
    if (c >= '0' && c <= '9') {
        return (c - '0');
    }
    else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 10);
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 10);
    }
}

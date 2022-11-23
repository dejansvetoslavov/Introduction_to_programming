#include <iostream>

unsigned long long Reverse(unsigned long long n)
{
    unsigned long long result = 0;
    short lastDigit;

    while (n != 0)
    {
        lastDigit = n % 10;
        (result *= 10) += lastDigit;
        n /= 10;
    }

    return result;
}

bool IsPalindrome(unsigned long long n) {
    return n == Reverse(n);
}

void PrintDoublePalindromes(unsigned k) {
    for (unsigned long long i = 11, counter = 0; i <= INT32_MAX && counter < k; i++) {
        if (IsPalindrome(i) && IsPalindrome(i * i)) {
            std::cout << i << " " << i * i << std::endl;
            counter++;
        }
    }
}

int main() {
    PrintDoublePalindromes(3);

    return 0;
}
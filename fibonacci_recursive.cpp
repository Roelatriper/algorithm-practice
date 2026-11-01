#include <iostream>

long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cin >> n;

    if (n < 1 || n > 40) {
        std::cout << "n must be between 1 and 40\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << fibonacci(i);
    }
    std::cout << '\n';

    return 0;
}

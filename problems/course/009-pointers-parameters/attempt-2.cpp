#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap_values(int* x, int* y);
void swap_addresses(int*& x, int*& y);

int main() {
    int x = 1, y = 2, *a, *b;
    swap_values(&x, &y);
    cout << x << y << endl;
    *a = 1;
    *b = 2;
    swap_addresses(a, b);
    cout << x << y;
    return 0;
}

void swap_addresses(int*& x, int*& y) {
    int* tmp = x;
    x = y;
    y = tmp;
}

void swap_values(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap_reference(int& x, int& y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void swap_pointer(int* x, int* y) {
    int* tmp;
    *tmp = *x;
    *x = *y;
    *y = *tmp;
}

int main() {
    int a = 8, b = 3, c = 0, d = -1;
    swap_reference(a, b);
    swap_pointer(&c, &d);
    cout << a << b << endl << c << d;
    swap_pointer(&d, &d);
    cout << endl << d;
    return 0;
}

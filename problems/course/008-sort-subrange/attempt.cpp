#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool down_sort(const int& a, const int& b) {
    return a > b;
}

int main() {
    int n, l, r;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> l >> r;
    sort(a.begin() + l - 1, a.begin() + r, down_sort);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}

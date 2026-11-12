#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool istrue(const int& a, const int& b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> ans(t);
    vector<vector<int>> ans_array(t);

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> h(n);
        vector<bool> visited(n, false);
        for (int j = 0; j < n; j++) {
            cin >> h[j];
        }
        sort(h.begin(), h.end(), istrue);

        int left = 0, right = n - 1, l_p = 0, r_p = 1;
        ans_array[i].resize(n);

        while (left <= right && (max(l_p, r_p) < n)) {
            if (left == 0 || ans_array[i][left - 1] != h[l_p]) {
                visited[l_p] = true;
                ans_array[i][left++] = h[l_p];
            }
            l_p = max(l_p, r_p) + 1;

            if (left > right || r_p >= n) break;

            if (right == n - 1 || ans_array[i][right + 1] != h[r_p]) {
                visited[r_p] = true; 
                ans_array[i][right--] = h[r_p];
            }
            r_p = max(l_p, r_p) + 1;
        }

        ans[i] = left + (n - 1 - right);

        if (left <= right) {
            int max_rem = -1;
            for (int ttmp = n - 1; ttmp >= 0; ttmp--) {
                if (!visited[ttmp]) {
                    max_rem = h[ttmp];
                    break;
                }
            }

            if (left == 0 || max_rem > ans_array[i][left - 1]) {
                ans[i]++;
                for (int k = left, ttmp = n - 1; k <= right; k++) {
                    while (visited[ttmp]) ttmp--;
                    visited[ttmp] = true;
                    ans_array[i][k] = h[ttmp];
                }
            } else {
                if (right == n - 1 || max_rem > ans_array[i][right + 1]) {
                    ans[i]++;
                }
                for (int k = right, ttmp = n - 1; k >= left; k--) {
                    while (visited[ttmp]) ttmp--;
                    visited[ttmp] = true;
                    ans_array[i][k] = h[ttmp];
                }
            }
        }
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
        for (int j = 0; j < (int)ans_array[i].size(); j++) {
            cout << ans_array[i][j] << (j + 1 == (int)ans_array[i].size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
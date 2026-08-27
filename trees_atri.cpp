//atri built on 15:59

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// -1 表示 null
Node* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < (int)arr.size()) {
        Node* cur = q.front();
        q.pop();
        if (arr[i] != -1) {                 // 左孩子
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < (int)arr.size() && arr[i] != -1) {  // 右孩子
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    vector<int> arr;
    string s;
    while (cin >> s) {           // 读完整行输入即结束
        if (s == "null") arr.push_back(-1);
        else arr.push_back(stoi(s));//stoi string to int
    }
    cout << maxDepth(buildTree(arr)) << endl;   // 3 9 20 null null 15 7 → 3
    return 0;
}
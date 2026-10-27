#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,nr;
    cin >> n >> m;
    vector<int> a(n),delta(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        delta[i]=(i==0?a[i]:(a[i]-a[i-1]));
    }
    vector<vector<int> > query(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)cin >> query[i][j];
        delta[query[i][0]-1]+=query[i][2];
        nr=query[i][1];
        if(nr<n)delta[nr]-=query[i][2];
    }
    for(int i=0;i<n;i++){
        if(i>0)delta[i]+=delta[i-1];
        cout << delta[i] << " ";
    }cout << endl;

    return 0;
}

/*
d[i] 表示什么？
区间 [l,r] 加 k 时，需要修改差分数组的哪两个位置？
所有修改结束后，怎样恢复最终数组？
- 数组的差分。
- l-1,r
- delta[i]+=delta[i-1];
*/
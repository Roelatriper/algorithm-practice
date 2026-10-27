#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,q,l=0,r,mid;
    queue<int> tmp;
    cin >> n >> q;
    vector<int> a(n),query(q),ans(q,-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<q;i++){
        cin >> query[i];
    }
    for(int i=0;i<q;i++){
        l=0;r=n-1;mid=n-1;
        while(r>=l){
            mid=(l+r)/2;
            if(a[mid]>=query[i]){
                ans[i]=((ans[i]>mid||ans[i]==-1)?(mid+1):ans[i]);
                r=mid-1;
            }else {
                l=mid+1;
            }
        }cout << ans[i] << endl;
    }


    return 0;
}

//若 a[mid] >= x，为什么不能立即返回 mid？接下来还要保留哪一侧继续找？
//若 a[mid] < x，可以确定排除哪一部分？
/*
    应该找左边，直到找到完数组以确定没有任何更前面的数字。
    排除左边。

*/

//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n,k,ans,sum=0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(i-k>=0)sum-=a[i-k];
        sum+=a[i];
        if(i<(k-1))continue;
        if(i==(k-1)){ans=sum;continue;}
        if(i>(k-1) && ans<sum)ans=sum;
    }
    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,q,left=0,right=0,ans=0,sum=0;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bool count=0;
    for(int i=0;i<n;i++){
        sum+=a[right++];
        while((sum>=q) && (left<=right)){
            if(count==false)ans=right-left;
            (ans>=(right-left))?(ans=right-left):1;
            sum-=a[left++];
            count=true;
        }
    }cout << ans << endl;
    

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,q,left=0,right=0,ans=-1,sum=0;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[right++];
        while((sum>=q) && (left<=right)){
            if(sum=q)(ans>=(right-left+1))?1:(ans=right-left+1);
            sum-=a[left++];
        }
    }cout << ans << endl;
    

    return 0;
}

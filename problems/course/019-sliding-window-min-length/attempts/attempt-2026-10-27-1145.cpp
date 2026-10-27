#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
    int n,tar,ans=0,sum=0,l=0;
    cin >> n >> tar;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
        for(;sum>=tar;l++){
            sum-=a[l];
            ans=((i-l+1<ans||ans==0)?i-l+1:ans);
        }
    }cout << ans << endl;

    return 0;
}

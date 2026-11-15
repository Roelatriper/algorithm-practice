#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    ll int n;
    cin >> n;
    vector<ll int> a(n),dp(n);
    for(ll int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==0){
        cout << 0 << endl;
        return 0;
    }dp[0]=a[0]>0?a[0]:0;
    if(n==1){
       cout << (a[0] > 0 ? a[0] : 0) << endl;
       return 0; 
    }dp[1]=a[0]>a[1]?a[0]:a[1];

    for(ll int i=2;i<n;i++){
        dp[i]=dp[i-2]+a[i]>dp[i-1]?dp[i-2]+a[i]:dp[i-1];

    }
    cout << dp[n-1] << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),dp(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==0){
        cout << 0 << endl;
        return 0;
    }dp[0]=a[0]>0?a[0]:0;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-2]+a[i]>dp[i-1]?dp[i-2]+a[i]:dp[i-1];

    }
    cout << dp[n-1] << endl;

    return 0;
}
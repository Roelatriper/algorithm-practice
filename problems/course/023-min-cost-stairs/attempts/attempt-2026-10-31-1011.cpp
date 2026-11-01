#include <iostream>
#include <vector>

using namespace std;

int main(){
    int_fast64_t n;
    cin >> n;
    vector<int_fast64_t> cost(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    vector<int_fast64_t> dp(n+1);
    if(n==1||n==0){
        cout << 1 << endl;
        return 0;
    }
    dp[0]=static_cast<int_fast64_t>(0);dp[1]=static_cast<int_fast64_t>(cost[0]);
    for(int i=2;i<=n;i++){
        dp[i]=
        ((dp[i-1]+cost[i-1])>(dp[i-2]+cost[i-1]))?
        (dp[i-2]+cost[i-1]):(dp[i-1]+cost[i-1]);
    }
    cout << dp[n] << endl;

    return 0;
}
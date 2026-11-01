#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll int> cost(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    vector<ll int> dp(n+1);
    if(n==1){
        cout << cost[0] << endl;
        return 0;
    }
    dp[0]=(0);dp[1]=(cost[0]);
    for(int i=2;i<=n;i++){
        dp[i]=
        ((dp[i-1]+cost[i-1])>(dp[i-2]+cost[i-1]))?
        (dp[i-2]+cost[i-1]):(dp[i-1]+cost[i-1]);
    }
    cout << dp[n] << endl;

    return 0;
}
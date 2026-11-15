#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> cost(n),dp(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
        if(i==0 || i==1)dp[i]=cost[i];
        else {
            dp[i]=((dp[i-1]>dp[i-2])?dp[i-2]:dp[i-1])+cost[i];
        }
    }
    cout << dp[n-1] << endl;


    return 0;
}
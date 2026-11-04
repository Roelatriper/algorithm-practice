#include <iostream>
#include <vector>
#define ll unsigned long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll int> cost(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }if(n==1){
        cout << cost[0] << endl;
        return 0;
    }
    vector<ll int> dp(n);
    dp[0]=cost[0];dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=(dp[i-1]>dp[i-2]?dp[i-2]:dp[i-1])+cost[i];
    }cout << dp[n-1] << endl;


    return 0;
}
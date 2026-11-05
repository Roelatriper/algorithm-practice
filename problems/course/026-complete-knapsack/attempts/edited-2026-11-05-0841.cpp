

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    vector<ll int> weight(n),value(n),dp(w+1);
    for(int i=0;i<n;i++)cin >> weight[i] >> value[i];
    for(int i=1;i<=w;dp[i++]=0){
        for(int j=0;j<n;j++)
            if(i-weight[j]>=0)
                dp[i]=dp[i]>(dp[i-weight[j]]+value[j])?dp[i]:dp[i-weight[j]]+value[j];
    }
    cout << dp[w] << endl;


    return 0;
}
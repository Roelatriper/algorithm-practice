#include <iostream>
#include <vector>

using namespace std;
#define ll long long
typedef vector<vector<ll int> > mapp;

int main(){
    ll int n,backpack;
    cin >> n >> backpack;
    mapp dp(n+1,vector<ll int>(backpack+1));
    mapp items(n,vector<ll int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin >> items[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=backpack;j++){
            if(j-items[i-1][0]>=0){
                dp[i][j]=(dp[i][j-items[i-1][0]]+items[i-1][1] > dp[i-1][j]) ? dp[i][j-items[i-1][0]]+items[i-1][1] : dp[i-1][j];
                dp[i][j]=dp[i][j]>dp[i-1][j-items[i-1][0]]+items[i-1][1]?dp[i][j]:dp[i-1][j-items[i-1][0]]+items[i-1][1];
            }
        }
    }
    cout << dp[n][backpack] << endl;

    return 0;
}

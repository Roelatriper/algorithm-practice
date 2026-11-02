#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    if(n==0){cout << 0 << endl;return 0;}
    vector<ll int> weight(n),value(n);
    for(int i=0;i<n;i++)cin >> weight[i] >> value[i];
    vector<vector<ll int> > dp(n,vector<ll int>(w+1));
    for(int i=0;i<n;i++){
        for(int c=0;c<w+1;c++)dp[i][c]=0;
    }
    for(int i=0;i<n;i++){
        for(int c=w;c>0;c--){
            if(c-weight[i]>=0){
                if(i!=0)dp[i][c]=
                dp[i-1][c-weight[i]]+value[i]>dp[i-1][c]?
                dp[i-1][c-weight[i]]+value[i]:dp[i-1][c];
                if(i==0)dp[0][c]=value[0];
            }else i!=0?dp[i][c]=dp[i-1][c]:1;
        }
    }cout << dp[n-1][w] << endl;

    return 0;
}
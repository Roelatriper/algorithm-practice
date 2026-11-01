#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<long long int> > cost(n,vector<long long int>(m));
    vector<vector<long long int> > dp(n,vector<long long int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> cost[i][j];
            if(i==0&&j==0)dp[0][0]=cost[0][0];
            else {
                if(i==0){
                    dp[0][j]=cost[0][j]+dp[0][j-1];
                    continue;
                }else if(j==0){
                    dp[i][0]=cost[i][0]+dp[i-1][0];
                    continue;
                }
                dp[i][j]=(((dp[i][j-1])>(dp[i-1][j]))?dp[i-1][j]:dp[i][j-1])+cost[i][j];
            }
        } 
    }
    cout << dp[n-1][m-1] << endl;


    return 0;
}
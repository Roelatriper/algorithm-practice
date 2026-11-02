#include <iostream>
#include <vector>

#define ll long long 
using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    vector<ll int> weight(n),value(n);
    for(int i=0;i<n;i++){
        cin >> weight[i] >> value[i];
    }
    vector<ll int> dp(w+1);
    for(int i=0;i<w+1;i++){dp[i]=0;}
    for(int i=0;i<n;i++){
        for(int c=w;c>=0;c--){
            if(c-weight[i]>=0)dp[c]=
            (dp[c-weight[i]]+value[i]>dp[c])?
            (dp[c-weight[i]]+value[i]):dp[c];            
        }
    }
    cout << dp[w] << endl;


    return 0;
}
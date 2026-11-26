#include <iostream>
#include <vector>
#define ll long long
using namespace std;


int main(){
    ll int T;
    cin >> T;
    vector<ll> ans(T);
    for(ll int i=0;i<T;i++){
       ll int x,b,d,k=1;
       vector<ll> dp;
       cin >> x >> b >> d;
       dp.push_back(b);
       if(b>=x)ans[i]=0;
       else do {
            dp.push_back(0);
            for(ll int j=0;j<=k/2;j++){
                ll A=dp[j]>dp[k-j-1]?dp[k-j-1]:dp[j];
                ll B=dp[j]<=dp[k-j-1]?dp[k-j-1]:dp[j];
                ll tmp=(A+(B-A<=d?B:A+d));
                dp[k]=dp[k]>tmp?dp[k]:tmp;
            }
       }while(dp[k++]<x);
       ans[i]=--k;
    //    cout << ans[i] << endl;
    }
    for(ll int i=0;i<T;i++){
        cout << ans[i] << endl;
    }




    return 0;
}
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
typedef vector<vector<ll int> > mapp;

int main(){
    int n,bp;
    cin >> n >> bp;
    mapp items(n,vector<ll int>(2));
    mapp dp_1(n+1,vector<ll int>(bp+1));
    vector<ll int> dp_2(bp+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)cin >> items[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=bp;j++){
            if(j-items[i-1][0]>=0){
                dp_1[i][j]=dp_1[i-1][j-items[i-1][0]]+items[i-1][1]>dp_1[i-1][j]?dp_1[i-1][j-items[i-1][0]]+items[i-1][1]:dp_1[i-1][j];
            }else {
                dp_1[i][j]=dp_1[i-1][j];
            }
        }
    }cout << dp_1[n][bp] << endl;
    for(int i=0;i<n;i++){
        for(int j=bp;j>=0;j--){
            if(j-items[i][0]>=0){
                dp_2[j]=dp_2[j-items[i][0]]+items[i][1]>dp_2[j]?dp_2[j-items[i][0]]+items[i][1]:dp_2[j];
            }
        }
    }cout << dp_2[bp] << endl;


    return 0;
}
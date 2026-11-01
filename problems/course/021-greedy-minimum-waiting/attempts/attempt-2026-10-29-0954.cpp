#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
bool istrue(int a,int b){
    return a<b;
}

int main(){
    ll int n,elapsed=0,ans=0;
    cin >> n;
    vector<ll int> t(n);
    for(ll int i=0;i<n;i++){
        cin >> t[i];
    }
    sort(t.begin(),t.end(),istrue);
    for(ll int i=0;i<n;i++){
        ans+=elapsed;
        elapsed+=t[i];
    }cout << ans << endl;

    return 0;
}
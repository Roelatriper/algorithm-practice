#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main(){
    int n,target,l=0,r;
    ll ans=0;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }r=n-1;
    while(l<r){
       (a[l]+a[r]<=target)?ans+=(r-(l++)):r-=1; 
    }cout << ans << endl;


    return 0;
}

//migration.
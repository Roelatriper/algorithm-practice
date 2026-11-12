#include <iostream>
#include <vector>
#define ll long long
using namespace std;
bool istrue(const ll int&a,const ll int &b){
    return a>b;
}

int main(){
    ll int n,m,max=0,tmp=0,less=0;
    cin >> n >> m;
    vector<ll int> a(n);
    for(ll int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),istrue);
    for(ll int i=0;i<n;i++){
        if(i==0){
            max=a[i]-m;
            continue;
        }else if(max<a[i]){
            tmp=a[i]-max+less;
            max+=tmp/(i+1);
            less=tmp%(i+1);
        }
    }
    cout << max << endl;

    return 0;
}

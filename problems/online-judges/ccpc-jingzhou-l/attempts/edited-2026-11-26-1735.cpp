#include <iostream>
#include <vector>
#define ll long long 
using namespace std;
ll calc(const ll &k,const ll &b,const ll &d){
    ll p=1;
    while(p*2<=k){p*=2;}
    return p*b+(k-p)*(b>d?d:b);
}

int main(){
    ll int T;
    cin >> T;
    vector<ll> ans(T);
    for(ll int i=0;i<T;i++){
        ll int x,b,d;
        cin >> x >> b >> d;
        ans[i]=0;
        if(x<=b){continue;}
        ll left=1,right=x;
        while(left<=right){
            ll mid=(left+right)/2;
            ll tmp=calc(mid,b,d);
            if(tmp>=x){
                right=mid-1;
                ans[i]=mid;
            }if(tmp<x){
                left=mid+1;
            }
        }ans[i]=left-1;
    }
    for(int i=0;i<T;i++){
        cout << ans[i] << endl;
    }


    return 0;
}

//2
//10 11 2 -> 0 x<=b
//4 2 3 -> 1 x>b
//最坏是x-1刀，就是有x的长度母棍却要求1子棍的情况。

//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll int t;
    cin >> t;
    vector<ll int> a(t),b(t),p(t),fin_ans(t);
    for(ll int i=0;i<t;i++){
        cin >> a[i] >> b[i] >> p[i];
        ll int base=a[i],exp=b[i],res=1;
        while(exp!=0){
            if(exp%2==0){
                base%=p[i];
                exp/=2;base=(base*base)%p[i];
            }else{
                exp-=1;res*=base;
                res%=p[i];
            }
        }fin_ans[i]=res%p[i];
    }
    for(ll int i=0;i<t;i++){
        cout << fin_ans[i] << endl;
    }
    



    return 0;
}
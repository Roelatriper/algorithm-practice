#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long 

int main(){
    ll int x,y,tmp=0,ans=0;
    cin >> x >> y;
    ll int sqrt_delta=sqrt(pow((2*y-1),2)+8*x);
    ll int min_n=((2*y-1-sqrt_delta))>=0?((2*y-1-sqrt_delta)):0;min_n/=2;
    ll int max_n=2*y-1+sqrt_delta;max_n/=2;
    if(max_n<=min_n){
        ans=0;
    }else {
        for(ll int i=1;tmp<=i;i++){
            flag:
            if(((i*(i+1))/2)<x+tmp*y){
                ans=(i-tmp)>ans?i-tmp:ans;
                continue;
            }else {
                if(tmp++>i){
                    break;
                }
                goto flag;
            }
        }
    }
    cout << ans+1 << endl;
    return 0;
}
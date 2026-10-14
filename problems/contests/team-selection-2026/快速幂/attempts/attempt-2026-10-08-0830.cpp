//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll int a,b,p;
    cin >> a >> b >> p;
    ll int result=1,base,exp;
    exp=b;base=a;
    while(exp!=1){
        if(exp%2==0){
            base=base*base;
            base%=p;
            exp/=2;
        }else{
            result*=base;
            result%=p;
            exp-=1;
        }
    }cout << result << endl;

    return 0;
}
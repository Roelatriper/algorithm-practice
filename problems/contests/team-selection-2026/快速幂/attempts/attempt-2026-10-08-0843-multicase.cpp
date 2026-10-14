//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll int t;
    cin >> t;
    vector<ll int> a(t),b(t),p(t);
    for(int i=0;i<t;i++)
        cin >> a[i] >> b[i] >> p[i];
    ll int result=1,base,exp;
    for(int i=0;i<t;i++){
        exp=b[i];base=a[i];
        base%=p[i];
        while(exp!=0){
            if(exp%2==0){
                base=base*base;
                base%=p[i];
                exp/=2;
            }else{
                result*=base;
                result%=p[i];
                exp-=1;
            }
        }cout << result << endl;
    }
    

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct tst{
    unsigned ll int a,b,p,ans;
    unsigned ll int tmp; 
};
int js(const int& a,const int& b){
    if(b==1)return a;
    else{if(b%2!=0){return pow(js(a,(b-1)/2),2)*a;}else return pow(js(a,b/2),2);}
}
int main(){
    unsigned ll int n;
    cin >> n;
    vector<tst> f(n);
    for(unsigned ll int i=0;i<n;i++){
        cin >> f[i].a >> f[i].b >> f[i].p;
        f[i].tmp=js(f[i].a,f[i].b);
        f[i].ans=f[i].tmp%f[i].p;
    }
    for(unsigned ll int i=0;i<n;i++){
        cout << f[i].ans << endl;
    }
    return 0;
}
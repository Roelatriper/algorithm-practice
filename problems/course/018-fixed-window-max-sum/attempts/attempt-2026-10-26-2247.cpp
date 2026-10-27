#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k,tmp=0,ans;
    cin >> n >> k;
    vector<int> a(n); 
    for(int i=0;i<n;i++){
        cin >> a[i];
        tmp+=a[i];
        if(i+1==k){
            ans=tmp;
        }
        if(i+1>k){
            tmp-=a[i-k];
            tmp>ans?ans=tmp:1;
        }
    }
    cout << ans << endl;
    return 0;
}

//减去i-k，加上i；在i+1地方实现

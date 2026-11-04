#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<ll int> a(n),query(q),delta(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        delta[i]=a[i];
        i==0?1:delta[i]-=a[i-1];
    }vector<vector<ll int> > edit(m,vector<ll int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)cin >> edit[i][j];
        delta[edit[i][0]-1]+=edit[i][2];
        edit[i][1]==n ? 1 : delta[edit[i][1]]-=edit[i][2];
    }
    for(int i=0;i<q;i++){
        cin >> query[i];
    }
    for(int i=1,tmp=0;i<=n && tmp<q;i<n?i++:1){
        if(i!=n)delta[i]+=delta[i-1];
        if(query[tmp]>=i || i==n){
            cout << delta[query[tmp]-1] << endl;
            tmp++;
        }
    }

    return 0;
}

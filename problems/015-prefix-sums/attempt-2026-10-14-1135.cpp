//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> sum(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[i]=((i!=0)?sum[i-1]:0)+a[i];
    }
    vector<vector<int> > b(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin >> b[i][0] >> b[i][1];
        b[i][0]-=1;b[i][1]-=1;
    }
    for(int i=0;i<q;i++){
        if(b[i][0]==b[i][1]){cout << 0 << endl;continue;}
        if(b[i][0]==0){
            cout << sum[b[i][1]] << endl;
        }else cout << sum[b[i][1]]-sum[b[i][0]-1] << endl;
        
    }
    

    return 0;
}
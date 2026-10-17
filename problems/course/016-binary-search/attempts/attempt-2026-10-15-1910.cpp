//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n,q,left=0,right,mid=0;
    cin >> n >> q;

    vector<int> s(n);
    vector<int> query(q);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<q;i++){
        cin >> query[i];
    }
    vector<bool> buffer(q);
    for(int tmp=0;tmp<q;tmp++){
        mid=n-1;right=n-1;
        while(left<=right){
            if(mid%2==0){
                mid/=2;
                if(s[mid]==query[tmp]){buffer[tmp]=1;break;}
                else{
                    (s[mid]<query[tmp]) ? (left=mid+1) : (right=mid-1);
                    mid=right-left;
                    if(mid==0 && (right!=0 || left!=0)){
                        if(s[mid]==query[tmp])buffer[tmp]=1;
                        else break;
                    }
                    continue;
                }
            }else mid-=1;
        }
        if(!buffer[tmp])buffer[tmp]=0;
    }
    for(int i=0;i<q;i++){
        if(buffer[i]==0)cout << "NO" << endl;
        else cout << "YES" << endl;}

    return 0;
}

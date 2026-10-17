//i file.the code could be changed at any time.plz backup important code before it change.

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
    for(int i=0;i<n;i++){
        left=0;right=n;

        while(left<=right){
            mid=(left+right)/2;
            if(s[mid]==query[i]){
                buffer[i]=1;
                break;
            }
            if(s[mid]>=query[i]){
                right=mid-1;
            }
            if(mid<=query[i]){
                left=mid+1;
            }
        }
    }
    for(int i=0;i<q;i++){
        if(buffer[i]==0)cout << "NO" << endl;
        else cout << "YES" << endl;}

    return 0;
}

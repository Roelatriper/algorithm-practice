//i file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n,q,left,right,mid;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> query(q);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }for(int i=0;i<q;i++){
        cin >> query[i];
    }bool istrue=0;
    for(int i=0;i<q;i++){
        istrue=0;left=0;right=n-1;
        while(left<=right){
            mid=right/2;
            if(a[mid]==query[i]){
                cout << "YES" << endl;
                istrue=1;
                break;
            }if(a[mid]>query[i]){
                right=mid-1;
            }if(a[mid]<query[i])left=mid+1;
        }if(istrue!=1)cout << "NO" << endl;   
    }
    
    return 0;
}

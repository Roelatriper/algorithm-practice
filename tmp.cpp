//i file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n,target,left=0;
    cin >> n >> target;
    int right=n-1;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    } 
    while(left<right){
        if(a[left]+a[right]==target){
            cout << "YES" << endl;
            return 0;
        }else a[left]+a[right]>target ? right-=1 : left+=1;
    }
    cout << "NO" << endl;
    return 0;
}
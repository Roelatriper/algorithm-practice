//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n,left=0,right,query;
    cin >> n >> query;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }right=n-1;
    
    while(left<right){
        if(query==(a[left]+a[right])){
            cout << "YES" << endl;
            return 0;
        }else query>(a[left]+a[right]) ? left+=1 : right-=1;
    }cout << "NO" << endl;
    return 0;
}

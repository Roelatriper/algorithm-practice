#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool istrue(const int& a,const int& b){
    return a<b;
}

int main(){
    int n,w,left=0,right,ans=0;
    cin >> n >> w;
    right=n-1;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),istrue);
    while(left<=right){
        if(a[left]+a[right]<=w){
            ans++;
            left++;right--;
        }else {
            ans++;
            right--;
        }
    }cout << ans << endl;


    return 0;
}
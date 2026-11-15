#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,w,left=0,right,ans=0;
    cin >> n >> w;
    right=n-1;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(left<=right){
        if(a[left]+a[right]<=w){
            ans++;
            left++;right--;
        }else {
            right--;
        }
    }cout << ((n%2!=0 && (2*a[n/2]>=w))?ans+1:ans) << endl;


    return 0;
}

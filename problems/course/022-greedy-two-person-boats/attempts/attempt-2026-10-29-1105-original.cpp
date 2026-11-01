#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,goal,left=0,right,ans=0;
    cin >> n >> goal;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }right=n-1;
    while(left<right){
        if(a[left]+a[right]>goal){
            ans++;
            right--;
        }
        if(a[left]+right<=goal){
            left++;right--;
            ans++;
        }
    }if(left==right)ans++;
    cout << ans << endl;

    return 0;
}

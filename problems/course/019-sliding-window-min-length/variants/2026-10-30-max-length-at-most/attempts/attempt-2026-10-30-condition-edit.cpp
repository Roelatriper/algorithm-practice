#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int j,n,target,tmp=0,ans=0,nl=0;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        tmp+=a[i];
        for(j=nl;tmp>=target;j++)tmp-=a[j];
        if(ans>=j-nl+2 || (ans==0 && tmp!=0)){
            ans=j-nl+2;nl=j;
        }
    }cout << ans << endl;


    return 0;
}

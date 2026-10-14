#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[3],b[3],tmp[3],ans;
    for(int i=0;i<3;i++){
        cin >> a[i] >> b[i];
        if(n%a[i]!=0){
            int j=n%a[i];
            n+=(a[i]-j);
        }
        tmp[i]=(n/a[i])*b[i];
    }ans=tmp[0];
    for(int i=1;i<=2;i++){
        ans = min(ans, tmp[i]);
    }
    cout << ans << endl;
    return 0;
}
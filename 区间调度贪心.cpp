#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[n+1][2],tmp[n+1],calc=1,ans=1;
    for(int i=1;i<=n;i++){
        cin >> array[i][0];
        cin >> array[i][1];
        tmp[i]=i;
    }
    for(int i=1;i<=n;i++){
        int temp=i;
        for(int j=i+1;j<=n;j++){
            if(array[tmp[temp]][1] > array[tmp[j]][1])temp=j;
        }
        int t = tmp[i];
        tmp[i] = tmp[temp];
        tmp[temp] = t;
    }
    for(int i=2;i<=n;i++){
        if(array[tmp[i]][0] >= array[tmp[calc]][1]){ans++;calc=i;}
    }
    cout << ans << endl;
    return 0;
}

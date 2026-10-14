#include <iostream>
#include <vector>
using namespace std;
struct pencil{
    int a;
    int b;
};
int main(){
    int n,tmp[3],proc[3],ans=0;
    vector<pencil> a(3);
    cin >> n;
    for(int i=0;i<3;i++)
        cin >> a[i].a >> a[i].b;
    memset(tmp,0,sizeof(tmp));
    memset(proc,0,sizeof(proc));
    for(int i=0;i<3;i++){
        tmp[i]=n%a[i].a;
        if(!tmp[i]){
            proc[i]=(n/a[i].a)*a[i].b;
            continue;
        }
        tmp[i]=a[i].a-tmp[i];
        int tmp_1=n;
        tmp_1+=tmp[i];
        proc[i]=(tmp_1/a[i].a)*a[i].b;
    }ans=proc[0];
    for(int i=1;i<3;i++){
        ans>=proc[i] ? ans=proc[i] : 1;
    }
    cout << ans <<endl;
    return 0;
}
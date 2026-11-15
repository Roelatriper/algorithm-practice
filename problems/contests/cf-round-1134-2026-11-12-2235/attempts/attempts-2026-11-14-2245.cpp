#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool istrue(const int &a,const int &b){
    return a < b;
}
void shelf_cnt(vector<int> &a){
    sort(a.begin(),a.end(),istrue);
    queue<int> tmp;
    int cnt=0;
    for(int i=2;i<(int)a.size();i++){
        if(a[i]>a[i-2]){
            cnt++;
        }
    }cout << cnt << endl;
    for(int i=1;i<(int)a.size();i+=2){
       cout << a[i]<< " ";
    }
    for(int i=(int)a.size()-((int)a.size()%2);i>=1;i-=2){
        cout << a[i] << " ";
    }cout << endl;
    return ;
}


int main(){
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        shelf_cnt(a);
    }


    return 0;
}
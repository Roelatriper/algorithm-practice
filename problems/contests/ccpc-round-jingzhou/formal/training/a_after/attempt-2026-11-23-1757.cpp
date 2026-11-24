#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int n,x_p,y_p,x_q,y_q;
int dealing(vector<vector<ll int> > &a){
    vector<ll int > specical,specical_2;
    int dx_q=x_q-x_p,dy_q=y_q-y_p;
    int tmp_down=0;
    for(int i=0;i<n;i++){
        int dx_a=a[i][0]-x_p,dy_a=a[i][1]-y_p;
        if(dx_a*dy_q-dy_a*dx_q >= 0){
            a[i][0]=2*x_p-a[i][0];
            a[i][1]=2*y_p-a[i][1];
            tmp_down++;
            specical.push_back((dx_a*dy_q-dy_a*dx_q));
        }
    }sort(specical.begin(),specical.end());
    
    
}

int main(){
    int T;
    cin >> T;
    for(int x_z=0;x_z<T;x_z++){
        cin >> n;
        vector<vector<ll int> > a(n,vector<ll int>(2));
        cin >> x_p >> y_p >> x_q >> y_q;
        for(int i=0;i<n;i++)cin >> a[i][0] >> a[i][1];
        cout << dealing(a) << endl;   
    }



    return 0;
}
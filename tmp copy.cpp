//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n,sum=0,len=0,goal,beg=0;
    cin >> n >> goal;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){
        sum+=a[i];len++;
        if(sum>=goal){
            for(int j=beg;sum>=goal;j++){
                if()
                sum-=a[j];len--;
                beg=j;
            }
        }
    }
    cout << len << endl;
    return 0;
}


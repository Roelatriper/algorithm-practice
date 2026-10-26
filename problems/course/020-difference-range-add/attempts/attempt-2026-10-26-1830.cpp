#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m,nl,nr;
    cin >> n >> m;
    vector<vector<int> > edit(m,vector<int>(3));
    vector<int> a(n),delta(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        delta[i]=(i==0?a[i]:a[i]-a[i-1]);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)cin >> edit[i][j];
        nl=(edit[i][0]-1);
        nr=(edit[i][1]==n?-1:edit[i][1]);
        delta[nl]+=edit[i][2];
        if(nr==-1)continue;
        delta[nr]-=edit[i][2];
    }
    cout << delta[0] << endl;
    for(int i=1;i<n;i++){
        delta[i]+=delta[i-1];
        cout << delta[i]<< endl;
    }
    return 0;
}

// u need to be aware of the actual output than problem output.some oj equal '\n' as no output.
// better to follow the rulesets according to problem output sample.

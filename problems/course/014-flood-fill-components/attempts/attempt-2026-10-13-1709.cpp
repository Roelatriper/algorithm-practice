#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > visited;
struct node{
    int x,y,dots;
};queue<node> pipe;
int a,b;
int bfs(const mapp& maps,visited& mapps){
    if(a==1 && b==1)return 1;
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    int anss=1;
    while(!pipe.empty()){
        node tmp=pipe.front();
        pipe.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+tmp.x,ny=dy[i]+tmp.y;
            if(nx<0 || ny<0 || nx>=a || ny>=b)continue;
            if(maps[nx][ny]=='#' || mapps[nx][ny]==1)continue;
            else{
                anss+=1;
                node ttmp;
                ttmp.x=nx;ttmp.y=ny;ttmp.dots=tmp.dots+1;
                pipe.push(ttmp);
                mapps[nx][ny]=1;
            }
        }
    }
    return anss;
}

int main(){
    cin >> a >> b;
    mapp maps(a,vector<char>(b));
    visited mapps(a,vector<bool>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> maps[i][j];
            mapps[i][j]=0;
        }
    }
    queue<int> ans;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(mapps[i][j]==0 && maps[i][j]!='#'){
                node tmp;
                tmp.x=i;tmp.y=j;tmp.dots=0;
                pipe.push(tmp);
                ans.push(bfs(maps,mapps));
            }else continue;
        }
    }
    int t=static_cast<int>(ans.size());
    cout << t << endl;
    for(int i=0;i<t;i++){
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}
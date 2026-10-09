#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > visited;

int a,b;

struct node{
    int x,y,neigh;
};queue<node> s;
queue<int> ans;

int bfs(const mapp& flood,visited& maps){
    node tmp;
    if(a==0 && b==0){return 0;}
    int dx[5]={1,-1,0,0,0},dy[5]={0,0,1,-1,0};
    int fin_ans=1;
    while(!s.empty()){
        tmp=s.front();
        s.pop();
        maps[tmp.x][tmp.y]=1;
        int nx,ny;
        for(int i=0;i<5;i++){
            nx=tmp.x+dx[i];ny=tmp.y+dy[i];
            if(nx<0 || ny<0 || nx>=a || ny>=b)continue;
            if(flood[nx][ny]!='#' && maps[nx][ny]==0){
                node ttmp;
                ttmp.x=nx;ttmp.y=ny;ttmp.neigh=tmp.neigh+1;
                s.push(ttmp);
                fin_ans++;
                maps[nx][ny]=1;
            }
        }
    }
    return fin_ans;
    
}

int main(){
    cin >> a >> b;
    mapp flood(a,vector<char>(b));
    visited maps(a,vector<bool>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> flood[i][j];
            maps[i][j]=0;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(maps[i][j]==0 && flood[i][j]!='#'){
                node tmp;
                tmp.x=i;tmp.y=j;tmp.neigh=0;
                s.push(tmp);
                ans.push(bfs(flood,maps));
            }else continue;
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<static_cast<int>(ans.size())+1;i++){
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}
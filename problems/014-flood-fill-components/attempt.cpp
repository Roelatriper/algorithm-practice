#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > visited;

int a,b;

struct node{
    int x,y,neigh;
};queue<node> s;
queue<int> ans;

void bfs(const mapp& flood,visited& maps){
    node tmp;
    if(a==0 && b==0){ans.push(0);return ;}
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    while(!s.empty()){
        tmp=s.front();
        if(maps[tmp.x][tmp.y]==1){
            s.pop();
            continue;
        }else{
            for(int i=0;i<4;i++){
                int nx=tmp.x+dx[i],ny=tmp.y+dy[i];
                if(nx<0 || ny<0 || nx>=a || ny>=b)continue;
                if(flood[nx][ny]=='#')continue;
                else{
                    if(maps[nx][ny]==0){
                        node ttmp;
                        ttmp.x=nx;ttmp.y=ny;ttmp.neigh=tmp.neigh+1;
                        ans.push(ttmp.neigh);
                        maps[nx][ny]=1;
                    }
                }
            }
        }
    }
    return ;
}

int main(){
    cin >> a >> b;
    mapp flood(a,vector<char>(b));
    visited maps(a,vector<bool>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> flood[i][j];
            maps[i][j]=0;
            if(flood[i][j]=='.'){
                node tmp;
                tmp.x=i;tmp.y=j;tmp.neigh=0;
                s.push(tmp);
            }
        }
    }
    bfs(flood,maps);
    int last=ans.front();
    ans.pop();
    for(int i=1;i<static_cast<int>(ans.size());i++){
        int tmp=ans.front();
        ans.pop();
        if(tmp < last){
            cout << tmp << endl;
        }
    }

    return 0;
}
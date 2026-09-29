#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > ppt;
int a,b;
struct bucket{
    int x,y,dist;
};queue<bucket> s;
bucket bfs(const mapp& m,ppt& visited){
    int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
    bucket cur;
    cur.x=0;cur.y=0;cur.dist=0;
    visited[0][0]=true;
    s.push(cur);
    if(cur.x==a-1 && cur.y==b-1){return cur;}
    while(!s.empty()){
        cur = s.front();
        s.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0 || ny<0 || nx>=a || ny>=b)continue;
            if(visited[nx][ny]!=1){
                if(m[nx][ny]!='#'){
                        if(nx==a-1 && ny==b-1){
                            cur.x=nx;cur.y=ny;
                            cur.dist++;
                            return cur;
                        }else {
                            bucket tmp;
                            tmp.x=nx;tmp.y=ny;
                            visited[tmp.x][tmp.y]=true;
                            tmp.dist=cur.dist+1;
                            s.push(tmp);
                        }
                }else continue;
            }else continue;
        }
    }
    cur.dist=-1;cur.x=-1;cur.y=-1;
    return cur;
}

int main(){
    cin >> a >> b;
    vector<vector<char> > m(a,vector<char>(b));
    vector<vector<bool> > visited(a,vector<bool>(b,0));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> m[i][j];
        }
    }
    bucket ans;
    ans=bfs(m,visited);
    cout << ans.dist << endl;
    return 0;
}
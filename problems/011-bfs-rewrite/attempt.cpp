#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int a,b,ans;
typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > vi;
struct node{
    int x,y,step;
};queue<node> line;
int bfs(const mapp& s,vi& visited){
    if(a==1 && b==1)return 0;
    else {
        node cur;cur.x=0;cur.y=0;cur.step=0;
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        line.push(cur);
        visited[0][0]=1;
        while(!line.empty()){
            cur=line.front();
            line.pop();
            // cout << cur.step << endl;
            for(int i=0;i<4;i++){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx<0 || ny<0 || nx>a-1 || ny>b-1)continue;
                if(nx==a-1 && ny==b-1){cur.step++;return cur.step;}
                if(s[nx][ny]!='#'){
                    if(visited[nx][ny]==0){
                        visited[nx][ny]=1;
                        node tmp;
                        tmp.x=nx;tmp.y=ny;
                        tmp.step=cur.step+1;
                        line.push(tmp);
                    }else continue;
                }else continue;
            }
            
        }
        return -1;
    }
} 

int main(){
    cin >> a >> b;
    vector<vector<char> > s(a,vector<char>(b));
    vector<vector<bool> > visited(a,vector<bool>(b,0));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> s[i][j];
        }
    }
    cout << bfs(s,visited) << '\n';
    return 0;
}
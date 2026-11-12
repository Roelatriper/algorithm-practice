#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef unsigned short int usi;
typedef vector<vector<usi> > mapp;
typedef vector<vector<bool> > visited;
usi n;
struct node{
    usi x,y;
};
queue<node> handle;
void bfs(mapp &squaure, visited &maps_){
    if(n==1){
        return ;
    }else {
        while(!handle.empty()){
            short int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
            node cur;
            cur=handle.front();
            handle.pop();
            for(int i=0;i<4;i++){
                int nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx<0 || ny<0 || nx>n+1 || ny>n+1)continue;
                if(squaure[nx][ny]==1 || maps_[nx][ny]==1)continue;
                maps_[nx][ny]=1;
                node tmp;
                tmp.x=nx;tmp.y=ny;
                handle.push(tmp);
            }
        }
    }
}

int main(){
    cin >> n;
    mapp squaure(n+2,vector<usi>(n+2));
    visited maps_(n+2,vector<bool>(n+2));
    for(usi i=1;i<=n;i++){
        for(usi j=1;j<=n;j++){
            cin >> squaure[i][j];
            maps_[i][j]=0;
        }
    }
    node tmp;
    tmp.x=0;tmp.y=0;
    handle.push(tmp);    
    bfs(squaure,maps_);
    for(usi i=1;i<=n;i++){
        for(usi j=1;j<=n;j++){
            if(maps_[i][j]==0 && squaure[i][j]==0){
                cout << "2" << " ";
            }else cout << squaure[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int> > maps;
typedef vector<vector<bool> > visited;
queue<pair<int,int> > handle;
int n,m,x,y;
void bfs(maps &maps_,visited &flag){
    if(n==1&&m==1){
        cout << "0" << endl;
        return ;
    }else {
        int dx[8]={2,1,2, 1,-2,-1,-2,-1},dy[8]={1,2,-1,-2,-1,-2,1,2};
            
        while(!handle.empty()){
            pair<int,int> cur=handle.front();
            handle.pop();
            for(int i=0;i<8;i++){
                int nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m)continue;
                if(flag[nx][ny])continue;
                flag[nx][ny]=1;
                maps_[nx][ny]=(maps_[cur.first][cur.second])+1;
                handle.push(make_pair(nx,ny));
            }
        }
    }
}


int main(){
    cin >> n >> m >> x >> y;
    maps maps_(n,vector<int>(m));
    visited flag(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){maps_[i][j]=0;flag[i][j]=0;}
    }
    handle.push(make_pair(x-1,y-1));
    flag[x-1][y-1]=1;
    bfs(maps_,flag);
    bool trigger=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(trigger==1 && maps_[i][j]==0)cout << "-1" << " ";
            else {
                if(maps_[i][j]==0)trigger=1;
                cout << maps_[i][j] << " ";
            }
        }cout << endl;
    }


    return 0;
}
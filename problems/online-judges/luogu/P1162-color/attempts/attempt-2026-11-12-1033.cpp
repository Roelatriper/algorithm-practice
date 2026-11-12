#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<bool> > maps;
queue<pair<int,int> > settle; int n;
void bfs(const maps& square,maps& visited){
    if(n==1)return ;
    else {
        while(!settle.empty()){
            int dx[4]={1,-1,-0,0},dy[4]={0,0,1,-1};
            auto cur=settle.front();
            settle.pop();
            for(int i=0;i<4;i++){
                int nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                if(square[nx][ny]==1||visited[nx][ny]==1)continue;
                visited[nx][ny]=1;
                settle.push(make_pair(nx,ny));
            }
        } 
    }
    return ;
}

int main(){
    cin >> n;
    maps square(n,vector<bool>(n));
    maps visited(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            if(tmp==1)square[i][j]=1;
            else square[i][j]=0;
            if((i!=0&&j==0)||(i==0&&j!=0))continue;
            if(!square[0][j]){
                settle.push(make_pair(0,j));
            }else if(!square[i][0]){
                settle.push(make_pair(i,0));
            }
        }
    }
    bfs(square,visited);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && square[i][j]==0){
                cout << "2" << " ";
            }else cout << square[i][j] << " ";
        }cout << endl;
    }


    return 0;
}
//写了个函数不调用的若智来了。

/*
1.1
1->1 测试边界条件

2.3
1 0 1
0 1 0
1 0 1
-> 
1 0 1
0 1 0
1 0 1 测试四周条件是否正确

3.5
1 1 1 1 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 1 1 1 1
->
1 1 1 1 1
1 2 2 2 1 
1 2 2 2 1
1 2 2 2 1
1 1 1 1 1
测试边界越界。
*/
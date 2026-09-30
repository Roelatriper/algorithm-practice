#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<char> > cch;
typedef vector<vector<bool> > map;
int rows,cols;

struct node{
    int x,y,step;
};queue<node> line;
node startNode,targetNode,ttmp;

int bfs(const cch& s,map& visited){
    if(rows==1&&cols==1)return 0;
    if(startNode.x==targetNode.x && startNode.y==targetNode.y)return 0;
    while(!line.empty()){
        startNode = line.front();
        line.pop();
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx=dx[i]+startNode.x,ny=dy[i]+startNode.y;
            if(nx<0 || ny<0 || nx>=rows || ny>=cols)continue;
            if(s[nx][ny]!= '#' && visited[nx][ny] != true){
                if(nx == targetNode.x && ny == targetNode.y){
                    return (startNode.step+1);
                }else {
                    ttmp.x=nx;ttmp.y=ny;ttmp.step=(startNode.step+1);
                    visited[nx][ny]=true;
                    line.push(ttmp);
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> rows >> cols;
    cch s(rows,vector<char>(cols));
    map visited(rows,vector<bool>(cols,false));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> s[i][j];
            if(s[i][j]=='S'){
                visited[i][j]=true;
                startNode.x=i;startNode.y=j;startNode.step=0;
                line.push(startNode);
            }if(s[i][j]=='T'){
                targetNode.x=i;targetNode.y=j;targetNode.step=0;
            }
        }
    }
    cout << bfs(s,visited) << endl;
    return 0;
}
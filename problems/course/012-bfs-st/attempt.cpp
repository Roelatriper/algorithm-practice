#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<char> > cch;
typedef vector<vector<bool> > map;

int a,b;
struct node{
    int x,y,step=0;
}; queue<node> line;
node start,ends;

int bfs(const cch& s,map& visited){
    if(a==1&&b==1)return 0;
    if(start.x == ::ends.x && start.y==::ends.y){return 0;}
    while(!line.empty()){
        node cur;
        cur=line.front();
        line.pop();
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(nx<0 || ny <0 || nx>=a || ny>=b)continue;
            if(s[nx][ny]!='#' && visited[nx][ny]!=1){
                    if(nx == ::ends.x && ny ==::ends.y){return (cur.step+1);}
                    else {
                        node tmp;
                        visited[nx][ny]=1;
                        tmp.x=nx;tmp.y=ny;tmp.step=cur.step+1;
                        line.push(tmp);
                    }
            }
        }
    }
    return -1;
}

int main(){
    
    cin >> a >> b;
    vector<vector<char> > s(a,vector<char>(b));
    vector<vector<bool> > visited(a,vector<bool>(b,0));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> s[i][j];
            if(s[i][j]=='S'){
                start.x=i;start.y=j;
                line.push(start);
            }if(s[i][j]=='T'){
                ::ends.x=i;::ends.y=j;
            }
        }
    }
    cout << bfs(s,visited) << endl;

    return 0;
}

//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// #define ll long long
using namespace std;
typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > visited;
int a,b,dots[2][2];
struct node{
    int x,y,dest;
};queue<node> pipe;


int bfs(const mapp &chr,visited &maps){
    node tmp;
    if(a == 1 && b == 1)return 0;
    while(!pipe.empty()){
        tmp=pipe.front();
        pipe.pop();
        maps[tmp.x][tmp.y]=1;
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx=dx[i]+tmp.x,ny=dy[i]+tmp.y;
            if(nx<0 || ny<0 || nx>=a || ny>=b)continue;
            if(nx==dots[1][0] && ny==dots[1][1])return (tmp.dest+1);
            if(maps[nx][ny]==0 && chr[nx][ny]!='#'){
                node ttmp;
                ttmp.x=nx;ttmp.y=ny;ttmp.dest=tmp.dest+1;
                pipe.push(ttmp);
                maps[ttmp.x][ttmp.y]=1;
            }else continue;
        }
        // cout << "loop" << endl;
    }
    return -1;
}

int main(){
    cin >> a >> b;
    mapp chr(a,vector<char>(b));
    visited maps(a,vector<bool>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> chr[i][j];
            maps[i][j]=0;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> dots[i][j];
        }
    }
    node tmp;
    tmp.x=dots[0][0];tmp.y=dots[0][1];tmp.dest=0;
    pipe.push(tmp);
    if(dots[0][0]==dots[1][0] && dots[1][1]==dots[0][1]){cout << 0 << endl;return 0;}
    
    cout << bfs(chr,maps) << endl;

    return 0;
}

/*E.g::
## 1.input:
{1 1 . 0 0 0 0} output:0

## 2.input:
{
3 5
..#..
..#..
.....
1 0 1 4
} output:6
#
## 3.input:
{3 3
......... 0 0 0 0}
output 0
 */

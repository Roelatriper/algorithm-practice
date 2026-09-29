#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a,b;


struct bucket{
    int x,y,dist;
};queue<bucket> s;
bucket bfs(int a,int b,char *m,bool *visited){
    int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
    bucket cur;
    cur.x=0;cur.y=0;cur.dist=0;
    s.push(cur);
    while(!s.empty()){
        cur = s.front();
        for(int i=0;i<4;i++){
            if(cur.x+dx[i]<0 || cur.y+dy[i]<0)continue;
            if(visited[cur.x+dx[i]][cur.y+dy[i]]!=1){
                if(m[cur.x+dx[i]][cur.y+dy[i]]!='#'){
                        if(cur.x+dx[i]==a-1 && cur.y+dy[i]==b-1){
                            cur.x+=dx[i];cur.y+=dy[i];
                            cur.dist++;
                            return cur;
                        }else {
                            bucket tmp;
                            tmp.x=cur.x+dx[i];tmp.y=cur.y+dy[i];
                            visited[tmp.x][tmp.y]=1;
                            tmp.dist=cur.dist++;
                            s.push(tmp);
                        }
                }else continue;
            }else continue;
        }
    }
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
    ans=bfs(a,b,&m,&visited);
    cout << ans.dist << endl;
    return 0;
}
/*
输入
3 4
..#.
....
#...

输出：
5

*/
#include<bits/stdc++.h>
using namespace std;
#define nline "\n"
int location[5][2];
int region[21][21];
int an[21][21];
int n,c,x,y;
int ans=99999;
int visited[21][21];
typedef struct node{
    int ro;
    int co;
    int dis;
}o;
void research(int row,int col){
    queue<o>q;
    o in;
    in.ro=row;
    in.co=col;
    in.dis=0;
    q.push(in);
    visited[row][col]=1;
    while(!q.empty()){
        o ok=q.front();
        q.pop();
        int nx=ok.ro;
        int ny=ok.co;
        int d=ok.dis;
        an[nx][ny]=d;
        if(nx-1>=0&&visited[nx-1][ny]==0&&region[nx-1][ny]){
        //int tm=visited[row-1][col];
        visited[nx-1][ny]=1;
        in.ro=nx-1;
        in.co=ny;
        in.dis=d+1;
        q.push(in);
      }
      if(ny-1>=0&&visited[nx][ny-1]==0&&region[nx][ny-1]){
        //int tm=visited[row-1][col];
        visited[nx][ny-1]=1;
        in.ro=nx;
        in.co=ny-1;
        in.dis=d+1;
        q.push(in);
      }
      if(nx+1<n&&visited[nx+1][ny]==0&&region[nx+1][ny]){
        //int tm=visited[row-1][col];
        visited[nx+1][ny]=1;
        in.ro=nx+1;
        in.co=ny;
        in.dis=d+1;
        q.push(in);
      }
      if(ny+1<n&&visited[nx][ny+1]==0&&region[nx][ny+1]){
        //int tm=visited[row-1][col];
        visited[nx][ny+1]=1;
        in.ro=nx;
        in.co=ny+1;
        in.dis=d+1;
        q.push(in);
      }
    }
}
void solve() {
    cin>>n>>c;
    for(int i=0;i<c;i++){
        cin>>x>>y;
        x--;
        y--;
        location[i][0]=x;
        location[i][1]=y;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>region[i][j];
        }
    }
    ans=9999;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            memset(visited,0,sizeof(visited));
            memset(an,1000,sizeof(an));
            int tmp=0;
            if(region[i][j]==1){
                //visited[i][j]=1;
                research(i,j);
                int f=0;
                for(int k=0;k<c;k++){
                    if(an[location[k][0]][location[k][1]]==1000){
                        f=1;
                        break;
                    }
                }
                if(!f){
                    for(int k=0;k<c;k++){
                    tmp=max(tmp,an[location[k][0]][location[k][1]]);
                    }
                    ans=min(ans,tmp);
                }
            }
        }
    }
    cout<<ans<<nline;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout<<"#"<<i<<" ";
        solve();
    }
    return 0;
}

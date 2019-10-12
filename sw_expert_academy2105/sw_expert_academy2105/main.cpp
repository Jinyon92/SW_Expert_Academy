#include<iostream>
using namespace std;

int T,n,counter,ans;
int map[20][20];
bool visited[20][20];
bool isExist[101];
int dy[4] = {1,1,-1,-1};
int dx[4] = {-1,1,1,-1};

void dfs(int y, int x, int dir, int cnt){
    if(visited[y][x]){
        if(counter == 0) counter++;
        else{
            ans = max(ans, cnt);
            return;
        }
    }
    if(dir >= 4) return;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || ny >= n  || nx < 0 || nx >= n){
        if(dir == 3) return;
        else dfs(y,x,dir+1, cnt);
    }else{
        if(!isExist[map[ny][nx]]){
            isExist[map[ny][nx]] = true;
            dfs(ny, nx, dir, cnt+1);
            dfs(ny, nx, dir+1, cnt+1);
            isExist[map[ny][nx]] = false;
        }
    }
    
}
int solve(){
    int ret = -1;
    for(int y=0; y<n-2; y++){
        for(int x=1; x<n-1; x++){
            visited[y][x] = true; ans = 0;
            counter = 0;
            dfs(y,x,0,0);
            visited[y][x] = false;
            for(int i=0; i<101; i++) isExist[i] = false;
            ret = max(ans, ret);
        }
    }
    if(ret == 0) return -1;
    return ret;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                cin>>map[y][x];
            }
        }
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}

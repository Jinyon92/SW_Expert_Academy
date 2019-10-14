#include<iostream>
#include<cstring>
using namespace std;

int map[16][16];
pair<int, int> start, arrive;
int visited[16][16];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int tc, ans;

void dfs(int y, int x){
    if(y == arrive.first && x == arrive.second){
        ans = 1; return;
    }
    for(int dir = 0; dir < 4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny > 16 || nx < 0 || nx > 16) continue;
        
        if(map[ny][nx] != 1 && !visited[ny][nx]){
            visited[ny][nx] = 1;
            dfs(ny, nx);
            visited[ny][nx] = -1;
        }
    }
}

int main()
{
    for(int T=1; T<=10; T++){
        cin>>tc;
        ans = 0;
        memset(visited, 0, sizeof(visited));
        for(int y=0; y<16; y++){
            for(int x=0; x<16; x++){
                scanf("%1d", &map[y][x]);
                if(map[y][x] == 2){
                    start.first = y; start.second = x;
                }
                if(map[y][x] == 3){
                    arrive.first = y; arrive.second = x;
                }
            }
        }
        visited[start.first][start.second] = 1;
        dfs(start.first, start.second);
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
}

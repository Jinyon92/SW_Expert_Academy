#include<iostream>
#include<queue>
#define INF 987654321
using namespace std;

int T,n;
int map[100][100];
int dp[100][100];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
queue< pair<int, int> > q;

void bfs(){
    q.push({0,0});
    dp[0][0] = 0;
    
    while(!q.empty()){
        auto now = q.front(); q.pop();
        int y = now.first; int x = now.second;
        for(int dir = 0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            
            int dist = dp[y][x] + map[ny][nx];
            if(dist < dp[ny][nx]){
                dp[ny][nx] = dist;
                q.push({ny,nx});
            }
        }
    }
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                scanf("%1d", &map[y][x]);
                dp[y][x] = INF;
            }
        }
        bfs();
        cout<<"#"<<test_case<<" "<<dp[n-1][n-1]<<"\n";
    }
    return 0;
}

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int map[9][9];
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int dx[8] = {0,1,-1,1,-1,0,1,-1};
int n, m;
queue<pair<int, int> > q;

void solve(int x, int y, int kind) {
    for(int dir=0; dir<8; dir++){
        int ny = y;
        int nx = x;
        while(1){
            ny += dy[dir];
            nx += dx[dir];
            if(ny <= 0 || ny > n || nx <= 0 || nx > n) {
                while(!q.empty()) q.pop();
                break;
            }
            
            if(map[ny][nx] != kind && map[ny][nx] != 0) {
                q.push({ny,nx});
            }else if(map[ny][nx] == kind){
                while(!q.empty()){
                    auto now = q.front();
                    map[now.first][now.second] = kind;
                    q.pop();
                }
                break;
            }
            else {
                while(!q.empty()) q.pop();
                break;
            }
        }
    }
}

int main()

{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        memset(map, 0, sizeof(map));
        cin >> n >> m;
        
        int div = n / 2;
        map[div][div] = 2;
        map[div][div + 1] = 1;
        map[div + 1][div] = 1;
        map[div + 1][div + 1] = 2;
        
        int y, x, kind;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> kind;
            map[y][x] = kind;
            solve(x, y, kind);
        }
        int black = 0, white = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == 1) black++;
                else if (map[i][j] == 2) white++;
            }
        }
        
        cout << "#" << test_case << " " << black << " " << white << "\n";
    }
}

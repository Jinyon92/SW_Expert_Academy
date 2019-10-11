#include<iostream>
#include<algorithm>
using namespace std;

struct POS{
    int y,x;
};
int T,n,k,ans;
int map[8][8];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
POS peak[5];
int peakCnt;

void dfs(POS now, int cnt){
    for(int dir = 0; dir<4; dir++){
        int ny = now.y + dy[dir];
        int nx = now.x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(map[now.y][now.x] > map[ny][nx]){
            POS next; next.y = ny; next.x = nx;
            dfs(next, cnt+1);
        }
    }
    ans = max(ans, cnt);
}
int solve(){
    for(int choose = 0; choose < peakCnt; choose++){
        for(int i=1; i<=k; i++){
            for(int y=0; y<n; y++){
                for(int x=0; x<n; x++){
                    map[y][x] -= i;
                    dfs(peak[choose], 1);
                    map[y][x] += i;
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <=T; test_case++){
        cin>>n>>k;
        int max_num = 0;
        peakCnt = 0; ans = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                cin>>map[y][x];
                max_num = max(max_num, map[y][x]);
            }
        }
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                if(map[y][x] == max_num){
                    peak[peakCnt].y = y;
                    peak[peakCnt++].x = x;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}

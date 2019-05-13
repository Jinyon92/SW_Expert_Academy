#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int map[1001][1001];
int n;
int ans;

void dfs(int x, int y, int cnt, int value)
{
    if(x >= n || y >= n) return;
    if(map[x][y] == 0) return;
    value *= map[x][y];
    while(value % 10 == 0){
        cnt += 1;
        value /= 10;
    }
    if(x == n-1 && y == n-1){
        ans = min(ans, cnt);
        return;
    }
    dfs(x+1, y, cnt, value);
    dfs(x, y+1, cnt, value);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        ans = 987654321;
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>map[i][j];
            }
        }
        dfs(0,0,0,1);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
        memset(map, 0, sizeof(map));
    }
    return 0;
}

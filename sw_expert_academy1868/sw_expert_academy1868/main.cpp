#include<iostream>
#include<queue>
using namespace std;

char map[300][300];
int temp[300][300];
bool visited[300][300];
int n, ans;
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int dx[8] = {1,0,-1,1,-1,1,0,-1};

void mine(int y, int x){
    for(int dir=0; dir<8; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        
        if(temp[ny][nx] != -1) temp[ny][nx]++;
    }
}

void bfs(int y, int x){
    queue< pair<int, int> > q;
    visited[y][x] = true;
    q.push(make_pair(y, x));
    
    while(!q.empty()){
        auto now = q.front();
        int cur_y = now.first;
        int cur_x = now.second;
        q.pop();
        for(int dir = 0; dir<8; dir++){
            int ny = cur_y + dy[dir];
            int nx = cur_x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            
            if(temp[ny][nx] == 0 && !visited[ny][nx]) q.push(make_pair(ny, nx));
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        ans = 0;
        cin>>n;
        
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                visited[y][x] = false;
                temp[y][x] = 0;
            }
        }
        
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                cin>>map[y][x];
                
                if(map[y][x] =='*'){
                    temp[y][x] = -1;
                    mine(y,x);
                }
            }
        }
        
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                if(!visited[y][x] && temp[y][x] == 0){
                    bfs(y,x);
                    ans++;
                }
            }
        }
        
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                if(!visited[y][x] && temp[y][x] > 0){
                    ans++;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}

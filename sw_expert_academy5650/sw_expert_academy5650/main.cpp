#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

int T,n,ans;
int map[101][101];
vector< pair<int,int> > start;
vector< pair<int,int> > worm_hole[5];
set < pair<int, int> > black_hole;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void init(){
    memset(map, 0, sizeof(map));
    start.clear();
    for(int i=0; i<5; i++){
        worm_hole[i].clear();
    }
    black_hole.clear();
    ans = 0;
}
int hit_block(int dir){
    if(dir == 0) return 1;
    else if(dir == 1) return 0;
    else if(dir == 2) return 3;
    else return 2;
}
int hit_worm_hole(int dir, int kind){
    if(kind == 1){
        if(dir == 0) return 1;
        else if(dir == 1) return 3;
        else if(dir == 2) return 0;
        else return 2;
    }else if(kind == 2){
        if(dir == 0) return 3;
        else if(dir == 1) return 0;
        else if(dir == 2) return 1;
        else return 2;
    }else if(kind == 3){
        if(dir == 0) return 2;
        else if(dir == 1) return 0;
        else if(dir == 2) return 3;
        else return 1;
    }else if(kind == 4){
        if(dir == 0) return 1;
        else if(dir == 1) return 2;
        else if(dir == 2) return 3;
        else return 0;
    }else{
        if(dir == 0) return 1;
        else if(dir == 1) return 0;
        else if(dir == 2) return 3;
        else return 2;
    }
}
pair<int, int> intoTheWormHole(pair<int, int> sp, int num){
    int ny, nx;
    for(int i = 0; i < 2; i++){
        if(worm_hole[num][i].first != sp.first || worm_hole[num][i].second != sp.second){
            ny = worm_hole[num][i].first;
            nx = worm_hole[num][i].second;
        }
    }
    return {ny,nx};
}
void solution(int cnt, int dir, pair<int, int> now, pair<int, int> sp){
    int ny = now.first;
    int nx = now.second;
    int ndir = dir;
    while(1){
        ny += dy[ndir];
        nx += dx[ndir];
        auto iter = black_hole.find({ny,nx});
        if(iter != black_hole.end()){
            ans = max(ans, cnt);
            break;
        }
        if(ny == sp.first && nx == sp.second){
            ans = max(ans, cnt);
            break;
        }
        if(nx < 0 || nx >= n || ny < 0 || ny >=n){
            int nextdir = hit_block(ndir);
            cnt++; ndir = nextdir;
        }else{
            if(map[ny][nx] >= 1 && map[ny][nx] <= 5){
                int nextdir = hit_worm_hole(ndir, map[ny][nx]);
                cnt++; ndir = nextdir;
            }else if(map[ny][nx] >= 6 && map[ny][nx] <= 10){
                pair<int, int> next = intoTheWormHole({ny,nx}, map[ny][nx]-6);
                ny = next.first;
                nx = next.second;
            }
        }
    }
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n;
        init();
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                cin>>map[y][x];
                if(map[y][x] == 0){
                    start.push_back({y,x});
                }else if(map[y][x] >= 6){
                    worm_hole[map[y][x] - 6].push_back({y,x});
                }else if(map[y][x] == -1){
                    black_hole.insert({y,x});
                }
            }
        }
        for(int i=0; i<start.size(); i++){
            for(int dir=0; dir<4; dir++){
                solution(0, dir, start[i], start[i]);
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}

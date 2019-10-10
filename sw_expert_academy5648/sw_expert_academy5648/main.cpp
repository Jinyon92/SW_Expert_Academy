#include<iostream>
#include<vector>
using namespace std;

int T,n;
struct INFO{
    int x,y,dir,energe;
};
vector<INFO> atom;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
int map[4001][4001];

int solve(){
    int ret = 0;
    while(!atom.empty()){
        for(int i=0; i<atom.size(); i++){
            INFO now = atom[i];
            int dir = now.dir;
            map[now.y][now.x] = 0;
            int nx = now.x + dx[dir];
            int ny = now.y + dy[dir];
            if(nx < 0 || nx > 4000 || ny < 0 || ny >4000){
                atom[i].energe = 0;
                continue;
            }
            atom[i].x = nx; atom[i].y = ny;
            map[ny][nx] += atom[i].energe;
        }
        
        for(int i=0; i<atom.size(); i++){
            if(atom[i].energe == 0) continue;
            if(map[atom[i].y][atom[i].x] != atom[i].energe){
                ret += map[atom[i].y][atom[i].x];
                map[atom[i].y][atom[i].x] = 0;
                atom[i].energe = 0;
            }
        }
        
        vector<INFO> temp;
        temp.assign(atom.begin(), atom.end());
        atom.clear();
        for(int i=0; i<temp.size(); i++){
            if(temp[i].energe != 0)
                atom.push_back(temp[i]);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n;
        INFO info;
        for(int i=0; i<n; i++){
            cin>>info.x>>info.y>>info.dir>>info.energe;
            info.x += 1000; info.y += 1000;
            info.x *= 2; info.y *= 2;
            atom.push_back(info);
        }
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}

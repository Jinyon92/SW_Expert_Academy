#include<iostream>
#include<cstring>
using namespace std;

struct INFO{
    int y,x,num,dir;
};
int T,n,m,k;
INFO bugs[1001];
int map[100][100][2];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int reverse_dir(int d){
    if(d==0) return 1;
    else if(d==1) return 0;
    else if(d==2) return 3;
    else return 2;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n>>m>>k;
        int y,x,num,dir;
        for(int i=1; i<=k; i++){
            cin>>y>>x>>num>>dir;
            bugs[i] = {y,x,num,--dir};
        }
        
        while(m--){
            memset(map, 0, sizeof(map));
            for(int i=1; i<=k; i++){
                INFO &now = bugs[i];
                if(now.num == 0) continue;
                
                now.y += dy[now.dir];
                now.x += dx[now.dir];
                if(now.y == n-1 || now.y == 0 || now.x == 0 || now.x == n-1){
                    now.num /= 2;
                    now.dir = reverse_dir(now.dir);
                }
                
                if(map[now.y][now.x][0]){
                    int idx = map[now.y][now.x][0];
                    bugs[idx].num += now.num;
                    if(map[now.y][now.x][1] < now.num){
                        map[now.y][now.x][1] = now.num;
                        bugs[idx].dir = now.dir;
                    }
                    now.num = 0;
                }else{
                    map[now.y][now.x][0] = i;
                    map[now.y][now.x][1] = now.num;
                }
            }
        }
        int ret = 0;
        for(int i=1; i<=k; i++){
            ret += bugs[i].num;
        }
        cout<<"#"<<test_case<<" "<<ret<<"\n";
    }
    return 0;
}

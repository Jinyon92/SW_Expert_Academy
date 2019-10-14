#include<iostream>
using namespace std;

int T, k;
int magnet[4][8];
int top_idx[4];
bool isSame[3];
bool visited[4];

void init(){
    if(magnet[0][(top_idx[0] + 2) % 8] == magnet[1][(top_idx[1] + 6) % 8]){
        isSame[0] = true;
    }else{
        isSame[0] = false;
    }
    if(magnet[1][(top_idx[1] + 2) % 8] == magnet[2][(top_idx[2] + 6) % 8]){
        isSame[1] = true;
    }else{
        isSame[1] = false;
    }
    if(magnet[2][(top_idx[2] + 2) % 8] == magnet[3][(top_idx[3] + 6) % 8]){
        isSame[2] = true;
    }else{
        isSame[2] = false;
    }
}

void solve(int num, int dir){
    visited[num] = true;
    if(num == 0){
        if(dir == 1){
            top_idx[0] -= 1;
            if(top_idx[0] == -1) top_idx[0] = 7;
            if(!isSame[0] && !visited[1]){
                solve(1,-1);
            }
        }else{
            top_idx[0] = (top_idx[0] + 1) % 8;
            if(!isSame[0] && !visited[1]){
                solve(1,1);
            }
        }
    }else if(num == 1){
        if(dir == 1){
            top_idx[1] -= 1;
            if(top_idx[1] == -1) top_idx[1] = 7;
            if(!isSame[1] && !visited[2]){
                solve(2,-1);
            }
            if(!isSame[0] && !visited[0]){
                solve(0,-1);
            }
        }else{
           top_idx[1] = (top_idx[1] + 1) % 8;
            if(!isSame[1] && !visited[2]){
                solve(2,1);
            }
            if(!isSame[0] && !visited[0]){
                solve(0,1);
            }
        }
    }else if(num == 2){
        if(dir == 1){
            top_idx[2] -= 1;
            if(top_idx[2] == -1) top_idx[2] = 7;
            if(!isSame[2] && !visited[3]){
                solve(3,-1);
            }
            if(!isSame[1] && !visited[1]){
                solve(1,-1);
            }
        }else{
            top_idx[2] = (top_idx[2] + 1) % 8;
            if(!isSame[2] && !visited[3]){
                solve(3,1);
            }
            if(!isSame[1] && !visited[1]){
                solve(1,1);
            }

        }
    }else if(num == 3){
        if(dir == 1){
            top_idx[3] -= 1;
            if(top_idx[3] == -1) top_idx[3] = 7;
            if(!isSame[2] && !visited[2]){
                solve(2,-1);
            }
        }else{
            top_idx[3] = (top_idx[3] + 1) % 8;
            if(!isSame[2] && !visited[2]){
                solve(2,1);
            }
        }
    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>k;
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                cin>>magnet[i][j];
            }
        }
        for(int i=0; i<4; i++) top_idx[i] = 0;
        int num, dir;
        for(int i=0; i<k; i++){
            cin>>num>>dir;
            init();
            for(int j=0; j<4; j++) visited[j] = false;
            solve(num-1, dir);
        }
        
        int cnt = 1; int ans = 0;
        for(int i=0; i<4; i++){
            ans += magnet[i][top_idx[i]] * cnt;
            cnt *= 2;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}

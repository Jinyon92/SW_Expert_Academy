#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int T,D,W,K;
int map[13][20];
bool visited[13];
vector<int> v;

int countBits(int n){
    int cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}
void modify(int pos, int num){
    for(int x=0; x<W; x++){
        map[pos][x] = num;
    }
}
void copy_arr(int a[13][20], int b[13][20]){
    for(int y=0; y<D; y++){
        for(int x=0; x<W; x++){
            a[y][x] = b[y][x];
        }
    }
}
bool is_verify(){
    for(int x=0; x<W; x++){
        int cnt = 1; int key = map[0][x];
        bool flag = false;
        for(int y=1; y<D; y++){
            if(key == map[y][x]){
                cnt++;
            }else{
                if(cnt >= K) flag = true;
                key = map[y][x];
                cnt = 1;
            }
        }
        if(cnt >= K) flag=true;
        if(!flag) return false;
    }
    return true;
}


int solve(){
    int ret = 987654321;
    if(is_verify()){
        return 0;
    }
    for(int subset = 1; subset < 1 << D; subset++){
        int bit_cnt = countBits(subset);
        if(bit_cnt < K){
            int temp[13][20] = {0,};
            for(int i=0; i<D; i++){
                if(subset & 1 << i){
                    v.push_back(i);
                }
            }
            copy_arr(temp, map);
            int standard = pow(2,bit_cnt);
            for(int i=0; i<standard; i++){
                for(int j=0; j<bit_cnt; j++){
                    if(i & 1 << j){
                        modify(v[j], 1);
                    }else{
                        modify(v[j], 0);
                    }
                }
                if(is_verify()){
                    ret = min(ret, bit_cnt);
                }
                copy_arr(map,temp);
            }
            v.clear();
        }
    }
    if(ret == 987654321) return K;
    return ret;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case<=T; test_case++){
        cin>>D>>W>>K;
        for(int y=0; y<D; y++){
            for(int x=0; x<W; x++){
                cin>>map[y][x];
            }
        }
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}

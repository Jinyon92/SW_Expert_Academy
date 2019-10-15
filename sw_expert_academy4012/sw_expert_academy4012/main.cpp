#include<iostream>
#include<vector>
using namespace std;

int T,n;
int cook[16][16];
vector<int> recipe1;
vector<int> recipe2;

int countBits(int n){
    int cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}

int solve(){
    int ret = 987654321;
    for(int subset = 0; subset < 1 << n; subset++){
        if(countBits(subset) == n/2){
            for(int i=0; i<n; i++){
                if(subset & 1 << i){
                    recipe1.push_back(i);
                }else{
                    recipe2.push_back(i);
                }
            }
            int sum1 = 0, sum2 = 0;
            for(int i=0; i<recipe1.size(); i++){
                for(int j=0; j<recipe1.size(); j++){
                    sum1 += cook[recipe1[i]][recipe1[j]];
                    sum2 += cook[recipe2[i]][recipe2[j]];
                }
            }
            int val = abs(sum1 - sum2);
            ret = min(ret, val);
            recipe1.clear();
            recipe2.clear();
        }
    }
    return ret;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <=T; test_case++){
        cin>>n;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                cin>>cook[y][x];
            }
        }
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}

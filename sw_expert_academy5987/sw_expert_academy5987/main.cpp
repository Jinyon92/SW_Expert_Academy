#include<iostream>
using namespace std;

int n, m;
int relation[16];
long long dp[1<<16];

long long solve(int flag){
    if(flag == (1<<n) - 1){
        return 1;
    }
    if(dp[flag] > 0){
        return dp[flag];
    }
    
    for(int i=0; i<n; i++){
        if((flag & 1<<i) > 0) continue;
        
        if((flag & relation[i]) == relation[i]){
            dp[flag] += solve(flag | 1<<i);
        }
    }
    
    return dp[flag];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>n>>m;
        
        int x, y;
        for(int i=0; i<m; i++){
            cin>>x>>y;
            x--;
            relation[y-1] |= (1<<x);
        }
        
        cout<<"#"<<tc<<" "<<solve(0)<<"\n";
        for(int i=0; i<n; i++) relation[i] = 0;
        for(int i=0; i< 1<<n; i++) dp[i] = 0;
    }
}

#include<iostream>
using namespace std;

int map[50][50];

int main()
{
    int T;
    cin>>T;
    
    int n;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>n;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                scanf("%1d", &map[y][x]);
            }
        }
        int ans = 0;
        int div = n/2;
        int start = 0, end = n-1;
        while(start <= div){
            ans += map[start][div];
            for(int i=div+1; i<=div+start; i++){
                ans += map[start][i];
            }
            for(int i=div-1; i>=div-start; i--){
                ans += map[start][i];
            }
            start++;
        }
        int cnt = 0;
        while(end > div){
            ans += map[end][div];
            for(int i=div+1; i<=div+cnt; i++){
                ans += map[end][i];
            }
            for(int i=div-1; i>=div-cnt; i--){
                ans += map[end][i];
            }
            end--;
            cnt++;
        }
        
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

struct Point{
    int y, x;
}custom[10];
int sx,sy,fx,fy;
int n, T;
int ans;
vector<int> num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    for(int test_case =1; test_case <= T; test_case++){
        cin>>n;
        cin>>sx>>sy>>fx>>fy;
        ans = INT_MAX;
        
        int x,y;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            num.push_back(i);
            custom[i].x = x;
            custom[i].y = y;
        }
        
        do{
            int sum = abs(sx-custom[num[0]].x) + abs(sy-custom[num[0]].y);
            for(int i=0; i<n-1; i++){
                sum += abs(custom[num[i]].y - custom[num[i+1]].y) + abs(custom[num[i]].x - custom[num[i+1]].x);
            }
            sum += abs(custom[num[n-1]].x - fx) + abs(custom[num[n-1]].y - fy);
            ans = min(ans,sum);
        }while(next_permutation(num.begin(), num.end()));
        
        cout<<"#"<<test_case<<" "<<ans<<"\n";
        num.clear();
    }
    
    return 0;
}

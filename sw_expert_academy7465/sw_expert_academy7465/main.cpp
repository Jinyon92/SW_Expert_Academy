#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int visit[101];
vector<int> con[101];

void dfs(int now)
{
    visit[now] = 1;
    for(auto a: con[now])
    {
        if(!visit[a])
        {
            dfs(a);
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int start, end;
            cin>>start>>end;
            con[start].push_back(end);
            con[end].push_back(start);
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(!visit[i])
            {
                ans += 1;
                dfs(i);
            }
        }
        memset(visit,0,sizeof(visit));
        for(int i=1; i<=n; i++)
        {
            con[i].clear();
        }
        cout<<ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

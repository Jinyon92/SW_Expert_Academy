#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int visited[26];

int main(int argc, char** argv)
{
    int test_case;
    int T,n;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        vector<string> v(n);
        getline(cin, v[0]);
        for(int i=0; i<n; i++){
            getline(cin, v[i]);
        }
        vector<int> v_count(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<v[i].size(); j++){
                if('A' <= v[i][j] && v[i][j] <= 'Z' && !visited[v[i][j] - 65]){
                    visited[v[i][j] - 65] = 1;
                    v_count[i]++;
                }
            }
            memset(visited, 0, sizeof(visited));
        }
        int max_value = v_count[0];
        for(int i=1; i<n; i++){
            max_value = max(max_value, v_count[i]);
        }
        vector<string> ans;
        for(int i=0; i<n; i++){
            if(max_value == v_count[i]){
                ans.push_back(v[i]);
            }
        }
        sort(ans.begin(), ans.end());
        cout<<"#"<<test_case<<" "<<ans[0]<<"\n";
    }
    return 0;
}

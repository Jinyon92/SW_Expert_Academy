#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<char> ans;
stack<int> s;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=0; i<n; i++)
        {
            int num;
            cin>>num;
            v[i] = num;
        }
        int idx = 0;
        for(int i=1; i<=n; i++)
        {
            s.push(i);
            ans.push_back('+');
            int now = s.top();
            while(now == v[idx])
            {
                s.pop();
                ans.push_back('-');
                if(idx + 1 < n && (!s.empty()))
                {
                    now = s.top();
                    idx++;
                }
                else if(idx + 1 < n && (s.empty()))
                {
                    idx++;
                }
                else if(idx + 1 == n) break;
            }
        }
        cout<<"#"<<test_case<<" ";
        if(ans.size() == 2*n){
            for(auto a : ans)
            {
                cout<<a;
            }cout<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        v.clear();
        ans.clear();
        while(!s.empty())
        {
            s.pop();
        }
    }
    return 0;
}

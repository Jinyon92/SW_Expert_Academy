#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int lefting[50];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        vector<int> lift(n);
        for(int i=0; i<n; i++){
            cin>>lift[i];
        }
        int m;
        cin>>m;
        vector<int> weight(m);
        for(int i=0; i<m; i++){
            cin>>weight[i];
        }
        sort(weight.begin(), weight.end());
        sort(lift.begin(), lift.end());
        int idx = 0;
        for(int i=0; i<m;){
            if(lift[idx] >= weight[i]){
                lefting[idx]++;
                i++;
            }else{
                if(idx < n-1){
                    idx++;
                }else{
                    break;
                }
            }
        }
        bool flag = true;
        if(lift[n-1] < weight[m-1]){
            flag = false;
        }
        int ans = 0;
        while(flag){
            bool find = false;
            for(int i=n-1; i>=0; i--){
                if(lefting[i]){
                    lefting[i]--;
                    find = true;
                }else{
                    for(int j=i-1; j>=0; j--){
                        if(lefting[j]){
                            lefting[j]--;
                            find = true;
                            break;
                        }
                    }
                }
            }
            if(!find) break;
            ans++;
        }
        if(flag) cout<<"#"<<test_case<<" "<<ans<<"\n";
        else {
            cout<<"#"<<test_case<<" "<<-1<<"\n";
            memset(lefting, 0, sizeof(lefting));
        }
    }
    return 0;
}



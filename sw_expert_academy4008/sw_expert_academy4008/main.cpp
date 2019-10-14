#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int T,n;
int Number[12];
int op[4];
vector<char> oper;

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <=T; test_case++){
        oper.clear();
        cin>>n;
        for(int i=0; i<4; i++){
            cin>>op[i];
        }
        for(int i=0; i<n; i++){
            cin>>Number[i];
        }
        while(op[0]){
            oper.push_back('+');
            op[0]--;
        }
        while(op[1]){
            oper.push_back('-');
            op[1]--;
        }
        while(op[2]){
            oper.push_back('*');
            op[2]--;
        }
        while(op[3]){
            oper.push_back('/');
            op[3]--;
        }
        
        sort(oper.begin(), oper.end());
        int max_ans = -INT_MAX; int min_ans = INT_MAX;
        do{
            int ret = Number[0];
            for(int i=0; i<oper.size(); i++){
                if(oper[i] == '+'){
                    ret += Number[i+1];
                }else if(oper[i] == '-'){
                    ret -= Number[i+1];
                }else if(oper[i] == '*'){
                    ret *= Number[i+1];
                }else if(oper[i] == '/'){
                    ret /= Number[i+1];
                }
            }
            max_ans = max(max_ans, ret);
            min_ans = min(min_ans, ret);
        }while(next_permutation(oper.begin(), oper.end()));
        
        cout<<"#"<<test_case<<" "<<max_ans-min_ans<<"\n";
    }
    return 0;
}

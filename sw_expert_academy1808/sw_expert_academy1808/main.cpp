#include<iostream>
#include<limits.h>
#include<string.h>
#include<math.h>
using namespace std;

bool number[10];
int X, ans;

bool isMake(string x){
    int xlen = x.length();
    for(int i=0; i<xlen; i++){
        if(!number[x[i] - '0']) return false;
    }
    return true;
}

int len(int x){
    return (int)log10(x)+1;
}

int find(int x, int cnt){
    if(isMake(to_string(x))){
        if(cnt == 0) ans = len(x) + 1;
        return len(x) + 1;
    }
    
    int ret = -1;
    for(int i = 2, end = sqrt(x) + 1; i < end; i++){
        if(x % i == 0 && isMake(to_string(i))){
            int len1 = len(i) + 1;
            int len2 = find(x/i, cnt+1);
            
            if(len2 != -1){
                ret = len1 + len2;
                if(ans > ret && x == X){
                    ans = ret;
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    
    for(int test_case = 1; test_case <= T; test_case++){
        ans = INT_MAX;
        for(int i=0; i<10; i++) number[i] = false;
        
        int num;
        for(int i=0; i<10; i++){
            cin>>num;
            if(num == 1) number[i] = true;
        }
        cin>>X;
        
        find(X,0);
        
        ans = (ans == INT_MAX ? -1 : ans);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    
    return 0;
}

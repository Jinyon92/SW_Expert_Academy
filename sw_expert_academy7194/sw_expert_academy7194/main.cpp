#include<iostream>
using namespace std;

int s,t,a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>s>>t>>a>>b;
        
        if(b==1){
            if((t-s) % a == 0){
                cout<<"#"<<tc<<" "<<(t-s)/a<<"\n";
            }else{
                cout<<"#"<<tc<<" "<<-1<<"\n";
            }
            continue;
        }
        int goHome = 0;
        while(s!=t) {
            if(t%b==0) {
                if(t/b < s) {
                    goHome++;
                    t -= a;
                }else {
                    goHome++;
                    t /= b;
                }
            }else {
                goHome++;
                t -= a;
            }
            if(s > t) {
                goHome = -1;
                break;
            }
        }
        cout<<"#"<<tc<<" "<<goHome<<"\n";
    }
    
    return 0;
}

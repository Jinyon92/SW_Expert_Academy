#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    int x1,y1,x2,y2,ans;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>x1>>y1>>x2>>y2;
        int x_gap = abs(x1-x2);
        int y_gap = abs(y1-y2);
        int max_gap = max(x_gap, y_gap);
        if(abs(x_gap - y_gap) % 2 == 0){
            ans = max_gap * 2;
        }else{
            ans = max_gap * 2 - 1;
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}

#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int s,e,m;
        cin>>s>>e>>m;
        ans = s;
        while(1)
        {
            if(ans % 24 == e)
            {
                if(ans % 29 == m)
                {
                    break;
                }
            }
            if(ans % 24 == e)
            {
                if(ans % 29 == 0 && m == 29)
                {
                    break;
                }
            }
            if(ans % 24 == 0 && e == 24)
            {
                if(ans % 29 == m)
                {
                    break;
                }
            }
            if(ans % 24 == 0  && e == 24)
            {
                if(ans % 29 == 0 && m == 29)
                {
                    break;
                }
            }
            ans += 365;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct INFO{
    int x,y,c,p;
};
int T,M,A;
vector<INFO> BCs;
int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

int check_point(int ax, int ay, int bx, int by){
    int sum = 0;
    vector< pair<int, int> >probableA;
    vector< pair<int, int> > probableB;
    int distA = 0, distB = 0;
    int size = BCs.size();
    for(int i=0; i<size; i++){
        distA = abs(BCs[i].x - ax) + abs(BCs[i].y - ay);
        distB = abs(BCs[i].x - bx) + abs(BCs[i].y - by);
        if(distA <= BCs[i].c) probableA.push_back({i,BCs[i].p});
        else probableA.push_back({i,0});
        if(distB <= BCs[i].c) probableB.push_back({i,BCs[i].p});
        else probableB.push_back({i,0});
    }
    for(int i=0; i<probableA.size(); i++){
        for(int j=0; j<probableB.size(); j++){
            if(probableA[i].first == probableB[j].first && probableA[i].second == probableB[j].second){
                sum = max(sum, probableB[j].second);
            }else{
                sum = max(sum, probableA[i].second + probableB[j].second);
            }
        }
    }
    return sum;
}

int main()
{
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin>>M>>A;
        vector<int> routeA(M);
        vector<int> routeB(M);
        for(int i=0; i<M; i++){
            cin>>routeA[i];
        }
        for(int i=0; i<M; i++){
            cin>>routeB[i];
        }
        int x,y,c,p,ans = 0;
        for(int i=0; i<A; i++){
            cin>>x>>y>>c>>p;
            BCs.push_back({x,y,c,p});
        }
        int ax = 1, ay = 1, bx = 10, by = 10;
        ans += check_point(ax, ay, bx, by);
        for(int i=0; i<M; i++){
            ax += dx[routeA[i]];
            ay += dy[routeA[i]];
            bx += dx[routeB[i]];
            by += dy[routeB[i]];
            ans += check_point(ax, ay, bx, by);
        }
        
        cout<<"#"<<test_case<<" "<<ans<<"\n";
        BCs.clear();
    }
    return 0;
}

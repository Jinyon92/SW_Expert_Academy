#include<iostream>
#include<stack>
using namespace std;

int arr[100];
stack<int> s;

int main()
{
    for(int test_case = 1; test_case <= 10; test_case++){
        int n;
        cin>>n;
   
        for(int i=0; i<n; i++){
            scanf("%1d", &arr[i]);
        }
        
        s.push(arr[0]);
        for(int i=1; i<n; i++){
            if(!s.empty()){
                if(s.top() == arr[i]){
                    s.pop();
                }else{
                    s.push(arr[i]);
                }
            }else{
                s.push(arr[i]);
            }
        }
        
        int idx = 0;
        while(!s.empty()){
            arr[idx++] = s.top();
            s.pop();
        }
        cout<<"#"<<test_case<<" ";
        for(int i=idx-1; i>=0; i--){
            cout<<arr[i];
        }
        cout<<"\n";
    }
}

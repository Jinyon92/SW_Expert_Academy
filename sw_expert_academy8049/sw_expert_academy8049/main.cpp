#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin>>str;
        string temp = "";
        bool isBoom = true;
        temp += str[0]; temp += str[1];
        int idx = 2;
        while(idx < str.size()){
            if(temp == "FF"){
                for(int i=idx; i<str.size(); i++){
                    if(str[i] == 'F') continue;
                    else{
                        idx = i;
                        temp = "";
                        break;
                    }
                }
                if(idx + 2 < str.size()){
                    temp += str[idx]; temp+= str[idx+1]; temp+= str[idx+2];
                    idx += 3;
                    if(temp == "MCM"){
                        if(idx < str.size()){
                            for(int i=idx; i<str.size(); i++){
                                if(str[i] == 'M') {
                                    idx++;
                                    continue;
                                }
                                else{
                                    idx = i;
                                    temp = "";
                                    break;
                                }
                            }
                            if(idx + 1 == str.size()){
                                idx++;
                            }
                            else if(idx + 1 < str.size()){
                                temp += str[idx]; temp += str[idx+1];
                                idx += 1;
                            }
                        }
                    }else{
                        isBoom = false;
                        break;
                    }
                }else{
                    isBoom = false;
                    break;
                }
            }else if(temp == "FC"){
                for(int i=idx; i<str.size(); i++){
                    if(str[i] == 'C') continue;
                    else{
                        idx = i;
                        temp = "";
                        break;
                    }
                }
                if(idx + 1 < str.size()){
                    temp += str[idx]; temp += str[idx+1];
                    idx += 2;
                    if(temp == "MF"){
                       if(idx + 1 < str.size()){
                           temp = "";
                           temp += str[idx]; temp += str[idx+1];
                           idx += 1;
                        }
                    }else{
                        isBoom = false;
                        break;
                    }
                }else{
                    isBoom = false;
                    break;
                }
            }else{
                isBoom = false;
                break;
            }
        }
        
        cout<<"#"<<test_case<<" ";
        if(isBoom){
            cout<<"DETECTED!";
        }else{
            cout<<"NOTHING!";
        }
    }
    return 0;
}

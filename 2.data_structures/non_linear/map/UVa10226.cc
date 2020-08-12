#include <bits/stdc++.h>

using namespace std;


int main(){
    int tt;
    cin>>tt;
    cin.ignore();
    string st;
    getline(cin,st);
    while(tt--){
        map<string,int> m;
        int pop = 0;
        while(getline(cin,st)){
            if(st.length()==0){
                break;
            }
            if(m.find(st)==m.end()){
                m[st] = 1;
            }else{
                m[st]++;
            }
            pop++;
        }

        for(auto it = m.begin();it!=m.end();it++){
            if(it!=m.begin()) printf("\n");
            cout<<it->first;
            printf(" %.4f",double(it->second)*100/pop);
        }
        if(tt) cout<<endl<<endl; else cout<<endl;

    }
    return 0;
}
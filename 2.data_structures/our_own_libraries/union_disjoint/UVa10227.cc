#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    string st;
    cin>>tt;
    cin.ignore();
    getline(cin,st);
    while(tt--){
        int p,t;
        cin>>p>>t;
        cin.ignore();
        set<vector<bool>> opi;
        vector<vector<bool>> ppl(p+1);
        for(int i = 0;i<=p;i++){
            ppl[i].assign(t+1,false);
        }
        while(getline(cin,st)){
            if(st.size()==0){
                break;
            }
            stringstream ss;
            ss<<st;
            int p1,t1;
            ss>>p1>>t1;
            ppl[p1][t1] = 1;
        }

        for(int i = 1;i<=p;i++){
            opi.insert(ppl[i]);
        }

        cout<<opi.size()<<endl;
        if(tt) cout<<endl;

    }
    return 0;
}
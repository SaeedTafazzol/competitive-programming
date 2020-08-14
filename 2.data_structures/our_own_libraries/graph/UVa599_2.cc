#include <bits/stdc++.h>

using namespace std;


int main(){
    int tt;
    cin>>tt;
    cin.ignore();


    while(tt--){
        int edges = 0;
        int vertices = 0;
        int acos = 0;
        int trees = 0;
        vector<bool> app;
        app.assign(26,false);
        string st;
        while(1){
            getline(cin,st);
            if(st[0]=='*'){
                break;
            }
            app[st[1]-'A'] = true;
            app[st[3]-'A'] = true;
            edges++;

            

        }
        for(int i = 0;i<26;i++){
            if(app[i]){
                vertices++;
            }
        }

        trees = vertices - edges;
        getline(cin,st);
        for(int i = 0;i<st.size();i+=2){
            if(!app[st[i]-'A']){
                acos++;
            }
        }


    

        printf("There are %d tree(s) and %d acorn(s).\n",trees,acos);


    }
    return 0;
}
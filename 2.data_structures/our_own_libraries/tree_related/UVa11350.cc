#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(b!=0){
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        pair<long long int,long long int> l,m,r;
        l = make_pair(0,1);
        m = make_pair(1,1);
        r = make_pair(1,0);
        string st;
        cin>>st;
        for(int i = 0;i<st.size();i++){
            if(st[i]=='R'){
                l = m;
                m = make_pair(m.first+r.first,m.second+r.second);
            }else{
                r = m;
                m = make_pair(m.first+l.first,m.second+l.second);
            }
        }
        cout<<m.first<<"/"<<m.second<<endl;
    }
    return 0;
}
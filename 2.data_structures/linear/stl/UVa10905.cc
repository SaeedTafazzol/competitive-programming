#include <bits/stdc++.h>


using namespace std;
bool comp(string & a,string & b){
    auto i = a.begin();
    auto j = b.begin();
    auto inI = i;
    auto inJ = j;
    while(i!=a.end() || j!=b.end()){
        if(i == a.end()){
            
            i = inI;
        }
        if((*j)=='\0'){
            
            j = inJ;
        }
        inI = i;
        inJ = j;

        while(i!=a.end() && j!=b.end()){

            if((*i)>(*j)){
                return true;
            }else if((*i)<(*j)){
                return false;
            }
            i++;
            j++;
        }
    }
    return true;

}

int main(){
    int n;
    scanf("%d",&n);
    vector<string> array(60);
    while(n){
        for(int i = 0;i<n;i++){
            cin>>array[i];
        }
        sort(array.begin(),array.begin() + n,comp);
        for(int i = 0;i<n;i++){
            cout<<array[i];
        }
        printf("\n");
        scanf("%d",&n);


    }
    return 0;

}
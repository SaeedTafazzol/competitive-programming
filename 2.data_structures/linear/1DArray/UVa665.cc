#include <bits/stdc++.h>

using namespace std;


int main(){
    int tt;
    cin>>tt;

    while(tt--){
        scanf("\n");
        int n,k;
        scanf("%d %d\n",&n,&k);
        int type[n];
        bool app[n];
        fill(type,type+n,-1);
        while(k--){
            int p;
            scanf("%d",&p);
            int c1[p],c2[p];
            fill(app,app+n,false);
            for(int i = 0;i<p;i++){ scanf("%d",c1 + i); app[c1[i]-1]=true;}
            for(int i = 0;i<p;i++){ scanf("%d",c2 + i); app[c2[i]-1]=true;}
            char comp;
            scanf("\n%c",&comp);
            if(comp!='='){
                for(int i = 0;i<n;i++){
                    if(!app[i]){
                        type[i]=1;
                    }
                }
            }
            switch (comp){
            case '<':
                for(int i = 0;i<p;i++){
                    switch (type[c1[i]-1]){
                    case -1:
                        type[c1[i]-1] = 0;
                        break;
                    case 2:
                        type[c1[i]-1] = 1;
                        break;
                    default:
                        break;
                    }
                    switch (type[c2[i]-1]){
                    case -1:
                        type[c2[i]-1] = 2;
                        break;
                    case 0:
                        type[c2[i]-1] = 1;
                        break;
                    default:
                        break;
                    }
                }
                break;
            case '>':  
                for(int i = 0;i<p;i++){
                    switch (type[c1[i]-1]){
                    case -1:
                        type[c1[i]-1] = 2;
                        break;
                    case 0:
                        type[c1[i]-1] = 1;                        
                        break;
                    default:
                        break;
                    }
                    switch (type[c2[i]-1]){
                    case -1:
                        type[c2[i]-1] = 0;
                        break;
                    case 2:
                        type[c1[i]-1] = 1;
                        break;
                    default:
                        break;
                    }
                }
                break;
            case '=':
                for(int i = 0;i<p;i++){
                    type[c1[i]-1]=1;
                    type[c2[i]-1]=1;
                }
                break;
            default:
                break;
            }
            cout<<endl<<"***********"<<endl;
            for(int i = 0;i<n;i++){
                cout<<i+1<<":"<<type[i]<<" ";
            }
            cout<<endl<<"***********"<<endl;
        }
        int broken = 0;
        for(int i = 0;i<n;i++){
            cout<<i+1<<":"<<type[i]<<" ";
            if(type[i]!=1){
                if(broken==0){
                    broken = i+1;
                }else{
                    broken = 0;
                    break;
                }
            }
        }
        cout<<endl;

        if(tt==0){
            cout<<broken<<endl;
        }else{
            cout<<broken<<endl<<endl;

        }
    }
    return 0;
}
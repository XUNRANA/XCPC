#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(n==1&&m==1){
        cout<<"No"<<endl;
        return ;
    }
    if(n==1&&m==2||n==2&&m==1){
        cout<<"Yes"<<endl;
        return ;
    }
    if(a==0&&b==0){
        cout<<"No"<<endl;
        return ;
    }
    if(a==0){
        if(n==1||m==1){
            cout<<"No"<<endl;
            return ;
        }
        if(n%2==0||m%2==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }else if(b==0){
        if(n==1){
            if(m%2==0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else if(m==1){
            if(n%2==0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }else{
        if(n%2==0||m%2==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}

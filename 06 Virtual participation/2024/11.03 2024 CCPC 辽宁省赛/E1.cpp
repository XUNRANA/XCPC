#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int > > ans(n+1,vector<int > (m+1));

    if(m%4==0){
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            int count=0;
            for(int j=1;j<=m;j++)
            {
                ans[i][j]=cnt;
                count++;
                if(count==4){
                    count=0;
                    cnt++;
                }
            }
        }
    }else if(n%4==0){
        int cnt=1;
        for(int j=1;j<=m;j++){
            int count=0;
            for(int i=1;i<=n;i++){
                ans[i][j]=cnt;
                count++;
                if(count==4){
                    count=0;
                    cnt++;
                }
            }
        }
    }else if(m>=6&&(m-6)%4==0&&n%2==0){
        int cnt=1;
        auto sd=[&](int x,int y){
            for(int j=y;j<y+3;j++){
                ans[x+1][j]=cnt;
            }
            ans[x][y]=cnt;
            cnt++;
            for(int j=y+3;j<y+3+3;j++){
                ans[x+1][j]=cnt;
            }
            ans[x][y+5]=cnt;
            cnt++;
            for(int j=y+1;j<y+1+4;j++){
                ans[x][j]=cnt;
            }
            cnt++;
        };
        for(int i=1;i<=n;i+=2){
            sd(i,1);
        }
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=7;j<=m;j++){
                ans[i][j]=cnt;
                count++;
                if(count==4){
                    count=0;
                    cnt++;
                }
            }
        }
    }else if(n>=6&&(n-6)%4==0&&m%2==0){
        int cnt=1;
        auto sd1=[&](int x,int y){
            for(int i=x;i<x+3;i++){
                ans[i][y]=cnt;
            }
            ans[x][y+1]=cnt;
            cnt++;
            for(int i=x+3;i<x+3+3;i++){
                ans[i][y]=cnt;
            }
            ans[x+5][y+1]=cnt;
            cnt++;
            for(int i=x+1;i<x+1+4;i++){
                ans[i][y+1]=cnt;
            }
            cnt++;
        };
        for(int j=1;j<=m;j+=2){
            sd1(1,j);
        }
        for(int j=1;j<=m;j++){
            int count=0;
            for(int i=7;i<=n;i++){
                ans[i][j]=cnt;
                count++;
                if(count==4){
                    count=0;
                    cnt++;
                }
            }
        }
    }else{
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


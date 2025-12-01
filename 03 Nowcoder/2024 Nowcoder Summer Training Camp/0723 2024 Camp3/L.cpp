#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a[9];
    for(int i=0;i<9;i++)
        cin>>a[i];
    
    string ans[9];
    for(int i=0;i<9;i++)
        ans[i] = "*********";
    
    int flag = 0;
    for(int i=1;i<8&&flag==0;i++){
        for(int j=1;j<8&&flag==0;j++){
            if(a[i][j]=='8'){
                ans[i][j]='8';
                flag=1;
                break;
            }
        }
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        if(i==(n-1))
        {
            if(a[i]=='1'||b[i]=='1') cout<<"1\n";
            else cout<<"0\n";
            return ;
        }
        else if(a[i]=='1'||b[i]=='1') continue;
        else
        {
            cout<<"0\n";
            return ;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

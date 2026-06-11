#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int s[1000010][32];
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll > a(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    if((sum&1)==1){
        cout<<"Alice"<<endl;
        return ;
    }


    for(int i=1;i<=n;i++){
        for(int j=0;j<31;j++){
            s[i][j]=((a[i]>>j)&1);
            if(j) s[i][j]+=s[i][j-1];
        }
    }

    auto check=[&](ll x){
        // x 1 2 3 4 5 
        vector<ll > b=a;
        int ok=0;   

        for(int i=1;i<=n;i++){
            ok+=s[i][x-1]+a[i]/(1<<x);
        }
        return ok&1;
    };

    for(int i=1;i<31;i++){
        ll x=(1ll<<i);
        if(x>k){
            break;
        }
        if(check(i)==1){
            cout<<"Alice"<<endl;
            return ;
        }
    }
    cout<<"Bob"<<endl;
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
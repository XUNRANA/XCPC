#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

ll sqr(ll x){
	ll l=0,r=1e9+10;
	while(r-l>1){
		ll mid=(r+l)/2ll;
		if(mid*mid<=x)	l=mid;
		else	r=mid;
	}return l;
}

void solve(){
    ll x;
    cin>>x;
    ll sq=sqr(x);
    if(x==sq*sq){
        cout<<2*sq+1<<endl;
    }else if(x>sq*(sq+1)){
        cout<<2*sq+3<<endl;
    }else{
        if((x-sq*sq)%2==sq%2){
            cout<<2*sq+2<<endl;
        }else{
            cout<<2*sq+3<<endl;
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

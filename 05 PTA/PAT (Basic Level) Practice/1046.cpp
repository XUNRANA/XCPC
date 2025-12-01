#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
void solve()
{
    int n;
    cin>>n;
    int a,b,c,d,ca=0,cb=0;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        if(a+c==b&&a+c!=d) cb++;
        if(a+c!=b&&a+c==d) ca++;
    }
    cout<<ca<<" "<<cb<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

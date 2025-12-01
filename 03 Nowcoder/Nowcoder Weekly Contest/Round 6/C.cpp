#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x=2,ax=1,ay=1,t,k;
    cin>>n;
    int s=n;
    for(int i=3;i<=13;i++)
    {
        x*=i;
        t=x-1;
        k=n/t;
        if(n-k*t<s&&k!=2)
        {
            s=n-k*t;
            ax=i;
            ay=k;
        }
        if((k+1)*t-n<s&&k!=1)
        {
            s=(k+1)*t-n;
            ax=i;
            ay=k+1;
        }
    }
    cout<<ax<<" "<<ay<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

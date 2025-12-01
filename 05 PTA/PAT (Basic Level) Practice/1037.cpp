#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int g1,s1,k1;
    int g2,s2,k2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g2,&s2,&k2);
    int p=g1*17*29+29*s1+k1;
    int a=g2*17*29+29*s2+k2;
    int d=a-p;
    int a1=d/(17*29);
    d%=17*29;
    d=abs(d);
    int a2=d/29;
    d%=29;
    cout<<a1<<"."<<a2<<"."<<d<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}


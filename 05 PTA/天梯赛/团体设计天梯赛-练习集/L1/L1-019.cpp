#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a,b,n,a1,b1,c1,d1;
	cin>>a>>b;
	cin>>n;
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a1>>b1>>c1>>d1;
        if(b1==d1) continue;
		if(a1+c1==b1) a--,ca++;
		if(a1+c1==d1) b--,cb++;
		if(a<0||b<0) break;
	}
	if(a<0) cout<<"A\n"<<cb<<"\n";
	else cout<<"B\n"<<ca<<"\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}


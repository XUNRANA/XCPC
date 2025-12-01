#include <bits/stdc++.h>
using namespace std;
long long n,q,op,k,s,ans;
void solve()
{
	cin>>n>>q;
	while(q--)
	{
		cin>>op;
		if(op==1) 
		{
			cin>>k;
			s+=k;
			if(s>n) ans++,s=0;
		}
		else cout<<ans<<"\n";
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

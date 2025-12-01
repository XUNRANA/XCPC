#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r;
int ck(int x,int y)
{
	fflush(stdout);
	cout<<"? "<<x<<" "<<y<<"\n\n";
	int t;
	cout.flush();
	cin>>t;
	return t;
}
void solve()
{
	l=1,r=999;
	while(r-l>1)
	{
		int l1=(2*l+r)/3;
		int l2=(l+2*r)/3;
		int t=ck(l1,l2);
		
		if(t==l1*l2) l=l2;
		else if(t==l1*(l2+1)) l=l1,r=l2;
		else r=l1;
	}
	cout<<"! "<<r<<"\n";
 
}
signed main()
{
 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,t;
	map<int,int>l,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(l.count(t)) r[t]=i;
		else l[t]=r[t]=i;
	}
	
	int ansl=1,ansr=n;
	int L=n,R=1;
	for(auto i:l)
	{
		int x=i.first;
		
		L=min(l[x],L);
		R=max(r[x],R);
		
		if(R-L+1>x)
		{
			cout<<"0\n";
			return ;
		}
		
		int nl=L-(x-(R-L+1));
		int nr=R+(x-(R-L+1));
		nl=max(nl,1);
		
		nr=min(nr,n);
		
		ansl=max(ansl,nl);
		ansr=min(ansr,nr);
	}
	

	
	if(ansl>ansr) cout<<"0\n";
	else cout<<ansr-ansl+1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

#include <bits/stdc++.h>
using namespace std;
int n,l[1000010],r[1000010],fa[1000010],fl,fr;

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n;
	fa[0]=0;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i],fa[i]=i;
	
	for(int i=1;i<=n;i++)
	{
		fl=find(l[i]-1);
		fr=find(r[i]);
		if(fl==fr) 
		{
			cout<<"0\n";
			return ;
		}
		fa[fl]=fr;
	}
	cout<<"1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

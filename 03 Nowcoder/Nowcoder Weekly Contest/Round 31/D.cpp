#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int q,op,x,y,c=0;
	map<int,int>l,r;
	cin>>q;
	r[0]=-1;
	l[-1]=0;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			c++;
			cin>>x>>y;
			r[x]=r[y];
			l[r[y]]=x;
			r[y]=x;
			l[x]=y;
		}
		else
		{
			c--;
			cin>>x;
			r[l[x]]=r[x];
			l[r[x]]=l[x];
		}
	}
	cout<<c<<"\n";
	for(int i=r[0];i!=-1;i=r[i]) cout<<i<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}


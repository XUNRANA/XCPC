#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int i;
	int x;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.x==a2.x) return a1.i<a2.i;
	return a1.x>a2.x;
}
void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++) a[i].i=i,a[i].x=0;
	int cur=0,c;
	set<int>del,add;
	
	while(q--)
	{
		int op,id,x;
		cin>>op;
		if(op==1) 
		{
			cin>>id;
			cur=id;
			del.clear();
			add.clear();
			c=m;
		}
		else if(op==2)
		{
			cin>>id>>x;
			if(x==cur)
			{
				if(del.count(id)||add.count(id)) continue;	
				add.insert(id);
				a[id].x+=c;
				c--;
			}
		}
		else 
		{
			cin>>id>>x;
			if(x==cur)
			{
				del.insert(id);
			}
		}
	}
	
	
	sort(a+1,a+1+m,cmp);
	
	for(int i=1;i<=m;i++) cout<<a[i].i<<" "<<a[i].x<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

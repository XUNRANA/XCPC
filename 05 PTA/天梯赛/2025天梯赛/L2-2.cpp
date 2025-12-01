#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int x0;
	int x1;
	int x2;
}ans[200010];
bool cmp(node ans1,node ans2)
{
	if(ans1.x1==ans2.x1) return ans1.x0<ans2.x0;
	return ans1.x1<ans2.x1;
}
int is[10000010];
void solve()
{
	int n;
	cin>>n;
	vector<int>a,b,c;
	for(int i=1;i<=n;i++) 
	{
		int x,y;
		cin>>x>>y;
		if(y==0) a.push_back(x);
		else if(y==1) b.push_back(x);
		else c.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	vector<int>na,nb,nc;
	na.push_back(a[0]);
	nb.push_back(b[0]);
	nc.push_back(c[0]);
	for(int i=1;i<a.size();i++)
	{
		if(a[i]!=a[i-1]) na.push_back(a[i]);
	}
	
	for(int i=1;i<b.size();i++)
	{
		if(b[i]!=b[i-1]) nb.push_back(b[i]);	
	}
	
	for(int i=1;i<c.size();i++)
	{
		if(c[i]!=c[i-1]) nc.push_back(c[i]);	
	}

	for(auto i:na) is[i+1000000]=1;
	int idx=1;
	for(auto i:nb)
	{
		for(auto j:nc)
		{
			if(2*i-j+1000000>=0&&is[2*i-j+1000000]) 
			{
				ans[idx].x1=i;
				ans[idx].x2=j;
				ans[idx].x0=2*i-j;
				idx++;
			}
		}
	}
	if(idx==1) cout<<"-1\n";
	else
	{
		sort(ans+1,ans+idx,cmp);
		for(int i=1;i<idx;i++) cout<<"["<<ans[i].x0<<", 0] ["<<ans[i].x1<<", 1] ["<<ans[i].x2<<", 2]\n";
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

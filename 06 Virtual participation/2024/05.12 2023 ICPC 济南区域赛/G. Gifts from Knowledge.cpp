#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define p 1000000007
vector<int>l[N];
int n,m,fa[2*N],ans,cnt;
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void Merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return ;
	fa[fx]=fy;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) l[i].clear();
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;j++) if(s[j-1]=='1') l[j].push_back(i);
	}
	
	for(int i=1;i<=m;i++)
	{
		if(l[i].size()+l[m+1-i].size()>2)
		{
			cout<<"0\n";
			return ;
		}
		else if(l[i].size()+l[m+1-i].size()==2)
		{
			if(l[i].size()==2||l[m+1-i].size()==2)
			{
				if(l[i].size()==2)
				{
					Merge(l[i][0],l[i][1]+n);
					Merge(l[i][1],l[i][0]+n);
				}
				else
				{
					Merge(l[m+1-i][0],l[m+1-i][1]+n);
					Merge(l[m+1-i][1],l[m+1-i][0]+n);
				}
			}
			else 
			{
				Merge(l[i][0],l[m+1-i][0]);
				Merge(l[i][0]+n,l[m+1-i][0]+n);
			}
		}
	}
	ans=1;
	cnt=0;
	for(int i=1;i<=2*n;i++) 
	if(fa[i]==i) cnt++;
	else if(i<=n&&fa[i]==fa[i+n])
	{
		cout<<"0\n";
		return ;
	}
	cnt/=2;
	while(cnt--)
	{
		ans<<=1;
		ans%=p;
	}
	cout<<ans<<'\n';
	//for(int i=1;i<=m;i++,cout<<'\n') for(auto j:h[i]) cout<<j<<" ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}

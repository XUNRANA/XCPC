#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int szl=5e5+5,P=131313131;
int n,m,q,fa[szl],rt,a[szl],dep[szl];
unordered_map<ull,int> mp;
vector<int> ed[szl];
ull hsh[szl],p[szl],bitr[szl],p2[szl];
void DFS(int x)
{
	int cnt=0;
	for(int y:ed[x])
	{
		cnt++;
		hsh[y]=hsh[x]*P+cnt;
		mp[hsh[y]]=y;
		dep[y]=dep[x]+1;
		DFS(y);
	}
	return;
}
void Add(int x,ull y)
{
	for(;x<=n;y*=p[x&-x],x+=x&-x) bitr[x]+=y;
}
ull Ask(int x)
{
	ull y=1,sum=0;
	for(;x;y*=p[x&-x],x-=x&-x) sum+=bitr[x]*y;
	return sum;
}
ull Ask(int l,int r)
{
	return Ask(r)-Ask(l-1)*p[r-l+1];
}	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>fa[i];
		if(!fa[i]) rt=i;
		else ed[fa[i]].push_back(i);
	}
	p[0]=1;
	for(int i=1;i<=m;i++) p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++) sort(ed[i].begin(),ed[i].end());
	DFS(rt);
	for(int i=1;i<=m;i++) cin>>a[i],Add(i,a[i]);
	for(int i=1;i<=q;i++)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x,l,r;
			cin>>x>>l>>r;
			int tmp=l;
			l--;
			while(l<r)
			{
				int mid=l+r+1>>1;
				if(mp.count(hsh[x]*p[(mid-tmp+1)]+Ask(tmp,mid))) l=mid;
				else r=mid-1;
			}
			tmp=mp[hsh[x]*p[(l-tmp+1)]+Ask(tmp,l)];
			if(tmp==0) cout<<x<<"\n";
			else cout<<tmp<<"\n";
		}
		else
		{
			int t,k;
			cin>>t>>k;
			Add(t,k-a[t]),a[t]=k;
		}
	}
}

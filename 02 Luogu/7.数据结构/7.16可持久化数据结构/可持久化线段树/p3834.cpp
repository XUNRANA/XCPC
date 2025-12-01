#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define lc(x) tr[x].l
#define rc(x) tr[x].r
int a[N];
struct node
{
	int l,r,s;
}tr[N*22];
int root[N],idx;
void build(int &x,int l,int r)
{
	x=++idx;//赋值，记得& 
	if(l==r) return ;
	int m=l+r>>1;
	build(lc(x),l,m);
	build(rc(x),m+1,r);
}
//x为前一版本，y为当前版本 
void insert(int x,int &y,int l,int r,int v)
{
	y=++idx;
	tr[y]=tr[x];
	tr[y].s++;
	if(l==r) return ;
	int m=l+r>>1;//双指针同步搜索 
	if(v<=m) insert(lc(x),lc(y),l,m,v);
	else insert(rc(x),rc(y),m+1,r,v);
}
//x为前一版本，y为当前版本 
int query(int x,int y,int l,int r,int k)
{
	if(l==r) return l;
	int m=l+r>>1;//双指针同步搜索 
	int s=tr[lc(y)].s-tr[lc(x)].s;
	if(k<=s) return query(lc(x),lc(y),l,m,k);
	else return query(rc(x),rc(y),m+1,r,k-s);
}
vector<int>v;
int getid(int x)
{
	//从1开始 
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void solve()
{
	int n,m,l,r,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end()); 
	int vn=v.size();
	build(root[0],1,vn);
	for(int i=1;i<=n;i++) insert(root[i-1],root[i],1,vn,getid(a[i])); 
	
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>k;
		cout<<v[query(root[l-1],root[r],1,vn,k)-1]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

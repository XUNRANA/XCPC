#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct node
{
	double x,y;
    int id;
}a[N],b[N];
struct node1
{
	int u,v;
	double w;
}e[2*N];
int n,m,fa[N],ans;
double k;
bool cmpx(node a1,node a2){ return a1.x<a2.x;}
bool cmpy(node a1,node a2){ return a1.y<a2.y;}
bool cmpw(node1 e1,node1 e2){ return e1.w<e2.w;}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool sol(int l,int r)
{
	if(l>=r) return 1;
	int mid=l+r>>1,cnt=0;
	if(!sol(l,mid)||!sol(mid+1,r)) return 0;
	while(a[l].x+k<a[mid].x) l++;
	while(a[r].x-k>a[mid].x) r--;
	for(int i=l;i<=r;i++) b[++cnt]=a[i];
	sort(b+1,b+1+cnt,cmpy);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=i+1;j<=cnt;j++)
		{
			if(b[j].y-b[i].y>k) break;
			if(fabs(b[j].x-b[i].x)<=k&&find(b[i].id)!=find(b[j].id)) return 0;
		}
	}
    return 1;
}

bool ck(int x)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=x;i++) fa[find(e[i].u)]=find(e[i].v);
	return sol(1,n);
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y,a[i].id=i; 
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(a+1,a+1+n,cmpx);
	sort(e+1,e+1+m,cmpw);
	int l=0,r=m;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
    // cout<<l<<"\n";
    printf("%.3f\n",e[ans].w);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}


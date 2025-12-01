#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,k;
struct node1
{
	int x1,x2,y;
}a[N];
bool cmp(node1 a1,node1 a2)
{
	if(a1.y==a2.y) return a1.x1<a2.x1;
	return a1.y<a2.y;
}
vector< pair<int,int> >g[3*N];
int fa[3*N];
int cnt=1;
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
}
void solve()
{
	cin>>n>>m>>k;	
	
	for(int i=1;i<=k;i++) 
	{
		cin>>a[i].x1>>a[i].x2>>a[i].y;
		if(a[i].y<3*N) g[a[i].y].push_back({a[i].x1,a[i].x2});
	}
	if(n==1)
	{
		cout<<"YES\n";
		return ;
	}
	
	if(m>2*k+1)
	{
		cout<<"NO\n";
		return ;
	}
	
	sort(a+1,a+1+k,cmp);
	
	int p=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i].y-p>2)
		{
			cout<<"NO\n";
			return ;
		}
		p=a[i].y;
	}
	
	if(m-p>=2)
	{
		cout<<"NO\n";
		return ;
	}

	for(int i=1;i<3*N;i++) fa[i]=i;
	
	vector<array<int,3>>t;
	sort(g[1].begin(),g[1].end());
	int s=1;
	for(auto j:g[1])
	{
		if(s<=j.first-1) t.push_back({s,j.first-1,cnt++});
		s=j.second+1;
	}
	if(s<=n) t.push_back({s,n,cnt++});
		
	
		
	for(int i=2;i<=m;i++)
	{
		sort(g[i].begin(),g[i].end());
		vector<array<int,3>>t1;
		int s=1;
		for(auto j:g[i])
		{
			if(s<=j.first-1) t1.push_back({s,j.first-1,cnt++});
			s=j.second+1;
		}
		if(s<=n) t1.push_back({s,n,cnt++});
		
		int j=0,j1=0;
		while(j<t.size()&&j1<t1.size())
		{
			int l=t[j][0];
			int r=t[j][1];
			int id=t[j][2];
			
			int l1=t1[j1][0];
			int r1=t1[j1][1];
			int id1=t1[j1][2];
			
			if(l1==r||r1==l||(r-l+1==1&&l1<=l&&l<=r1)||(r1-l1+1==1&&l<=l1&&l1<=r))//恰好一个交集 
			{
				if(!merge(id,id1))
				{
					cout<<"NO\n";
					return ;
				}	
				if(l1==r) j++;
				else if(r1==l) j1++;
				else if(r-l+1==1&&l1<=l&&l<=r1) j++;
				else j1++;
			}
			else if(r<l1) 
			{
				j++;
			}
			else if(r1<l)
			{
				j1++;
			}
			else
			{
				cout<<"NO\n";
				return ;
			}
		}
		t=t1;
	}
	cout<<"YES\n";
}


/*
11 3 5
1 3 1
9 11 1
5 7 2
1 3 3
9 11 3
YES
11 3 5
1 3 1
9 11 1
5 7 2
1 3 3
8 11 3
NO
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

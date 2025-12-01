#include <bits/stdc++.h>
using namespace std;
int n,nq,tr[100010];
long long ans;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}

struct node
{
	int x,i;
}a[100010];
bool cmp(node a1,node a2)
{
	return a1.x<a2.x;
}

struct qu
{
	int l,r,i;
}q[100010];
bool cmpq(qu q1,qu q2)
{
	return q1.l>q2.l;
}

void solve()
{
	cin>>n>>nq;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x;
		a[i].i=i; 
	}
	sort(a+1,a+1+n,cmp);
	vector<pair<int,int>>v;
	v.push_back({a[1].i,a[2].i});
	v.push_back({a[n].i,a[n-1].i});
	for(int i=2;i<=n-1;i++)
	{
		if(a[i].x-a[i-1].x<a[i+1].x-a[i].x) v.push_back({a[i].i,a[i-1].i});
		else if(a[i].x-a[i-1].x>a[i+1].x-a[i].x) v.push_back({a[i+1].i,a[i].i});
		else
		{
			v.push_back({a[i].i,a[i-1].i});
			v.push_back({a[i+1].i,a[i].i}); 
		}
	}
	for(auto &i:v) if(i.first>i.second) swap(i.first,i.second);
	sort(v.begin(),v.end(),greater<pair<int,int>>());
	for(int i=1;i<=nq;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].i=i;
	}
	sort(q+1,q+1+nq,cmpq);
	int j=0;
	for(int i=1;i<=nq;i++)
	{
		while(j<v.size()&&v[j].first>=q[i].l)
		{
			add(v[j].second,1);
			j++;
		}
		ans+=query(q[i].r)*q[i].i;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 

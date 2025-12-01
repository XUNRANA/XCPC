#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 1000010
int t[N],b[N],o,n,m;
char ch;
struct qy
{
	int op,c,s;
}q[N];
struct BIT
{
	int t[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		while(i<=o)
		{
			t[i]+=x;
			i+=lowbit(i);
		}
	}
	int sum(int i)
	{
		int res=0;
		while(i)
		{
			res+=t[i];
			i-=lowbit(i);
		}
		return res;
	}
}t1,t2;

signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ch>>q[i].c>>q[i].s;
		b[++o]=q[i].s;
		q[i].op=(ch=='U')?1:2;
	}
	sort(b+1,b+1+o);
	o=unique(b+1,b+1+o)-b-1;
	for(int i=1,x;i<=m;i++)
	{
		q[i].s=lower_bound(b+1,b+1+o,q[i].s)-b;
		if(q[i].op==1)
		{
			if(t[q[i].c]) x=t[q[i].c],t1.add(x,-1),t2.add(x,-b[x]);
			x=t[q[i].c]=q[i].s;
			t1.add(x,1);
			t2.add(x,b[x]);
		}
		else
		{
			x=t1.sum(o)-t1.sum(q[i].s-1);//大于s的个数
			int s1=t2.sum(q[i].s-1);
			if(s1>=(q[i].c-x)*b[q[i].s]) cout<<"TAK\n";
			else cout<<"NIE\n"; 
		}	
	}	
}


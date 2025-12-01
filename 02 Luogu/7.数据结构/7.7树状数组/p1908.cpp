#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],n,t,ans,r[500010];
int lowbit(int x)
{
	return x&-x;
}
void update(int i,int x)
{
	while(i<=n)
	{
		a[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=a[i];
		i-=lowbit(i);
	}
	return res;
}
struct node
{
	int v,i;
}b[500010];
bool cmp(node b1,node b2)
{
	return b1.v<b2.v;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i].v,b[i].i=i;
	sort(b+1,b+1+n,cmp);
	
	for(int i=1;i<=n;i++) r[b[i].i]=i;
	
	
	for(int i=1;i<=n;i++) 
	{
		update(r[i],1);
		ans+=i-sum(r[i]);
	}
	cout<<ans<<"\n";
}

/*
6
5 4 2 6 3 1
*/
/*
0 0 0 0 1 0
0 0 0 1 0 0 
0 1 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0
1 0 0 0 0 0
*/

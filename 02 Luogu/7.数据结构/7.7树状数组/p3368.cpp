//²î·Ö
#include <bits/stdc++.h>
using namespace std;
int n,q,a[500010],b[500010],op,l,r,x,ans;
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
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>b[i];
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>l>>r>>x;
			update(l,x);
			update(r+1,-x);
		}
		else
		{
			cin>>l;
			cout<<b[l]+sum(l)<<"\n";
		}
	}
} 

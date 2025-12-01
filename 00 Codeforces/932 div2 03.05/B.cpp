#include <bits/stdc++.h>
using namespace std;
int n,p,p1,mi,a[100010];
map<int,int>m,m1;
void solve()
{
	cin>>n;
	m.clear();
	m1.clear();
	for(int i=1;i<=n;i++) cin>>a[i],m[a[i]]++;
	if(m[0]==0)
	{
		cout<<"2\n1 1\n2 "<<n<<"\n";
		return ;
	}
	if(m[0]==1)
	{
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(m[i]<2)
		{
			if(m[i]==1)
			{
				cout<<"-1\n";
				return ;
			}
			else 
			{
				p=i;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<p) m1[a[i]]=1;
		if(m1.size()==p) 
		{
			p1=i+1;
			break;
		}
	}
	m1.clear();
	for(int i=p1;i<=n;i++)
	{
		if(a[i]<p) m1[a[i]]=1;
		if(m1.size()==p)
		{
			cout<<"2\n";
			cout<<"1 "<<p1-1<<"\n";
			cout<<p1<<" "<<n<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
int a[110],n,f;
void solve()
{
	cin>>n;
	for(int i=n;i>=0;i--) cin>>a[i];
	f=1;
	for(int i=n;i>=0;i--)
	{
		if(!a[i]) continue;
		if(f)
		{
			if(a[i]==-1) cout<<"-";
			else if(a[i]==1) ;
			else cout<<a[i];
			
			if(i>1) cout<<"x^"<<i;
			else if(i==1) cout<<"x";
			f=0;
		}
		else 
		{
			if(a[i]>0) 
			{
				cout<<"+";
				if(a[i]!=1||i==0) cout<<a[i];
			}
			else 
			{
				cout<<"-";
				if(a[i]!=-1||i==0) cout<<-a[i];
			}
			if(i>1) cout<<"x^"<<i;
			else if(i==1) cout<<"x";
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

#include <bits/stdc++.h>
using namespace std;
int n,k,a[200010],index;
void solve()
{
	cin>>n>>k;
	int cnt=0;
	if(n==1) 
	{
		cout<<k<<"\n";
		return ;
	}
	
	for(int i=30;i>=0;i--)
	{
		if(k>>i&1) 
		{
			if(cnt==0) index=i;
			cnt++;
		}
	}
	

	if(cnt==index+1)
	{
		cout<<k<<" ";
		for(int i=1;i<n;i++) cout<<"0 ";
		cout<<"\n";
		return ;
	}
	else
	{
		cout<<(1<<index)-1<<" "<<k-((1<<index)-1)<<" ";
		for(int i=1;i<n-1;i++) cout<<"0 ";
		cout<<"\n";
		return ;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}

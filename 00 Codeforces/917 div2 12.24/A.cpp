#include <bits/stdc++.h>
using namespace std;
long long t1,t2,t3,i1,i2,f,n;
void solve()
{
	t1=t2=f=i1=i2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t3;
		if(t3>0) t1++,i1=i;
		else if(t3<0) t2++,i2=i;
		else f=1;
	}
	
	if(f==1||t2%2==1) cout<<"0\n";
	else
	{
		cout<<"1\n";
		if(t1) cout<<i1<<" 0\n";
		else cout<<i2<<" 0\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	cin>>t;
	while(t--) solve();
}

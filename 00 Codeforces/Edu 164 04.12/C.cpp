#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==b[i]) continue;
		else
		{
			char ma=max(a[i],b[i]),mb=min(a[i],b[i]);
			a[i]=ma;
			b[i]=mb;
			for(int j=i+1;j<a.size();j++)
			{
				char ma=max(a[j],b[j]),mb=min(a[j],b[j]);
				a[j]=mb;
				b[j]=ma;
			}
			break;
		}
	}
	cout<<a<<"\n";
	cout<<b<<"\n";
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=0;
	cin>>t;
	while(t--) solve();
}

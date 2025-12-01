#include <bits/stdc++.h>
using namespace std;
long long n,s,s1,a[10];
void solve()
{
	cin>>n;
	s1=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s=1;
		a[i]+=1;
		for(int j=1;j<=n;j++) s*=a[j];
		a[i]-=1;
		s1=max(s1,s);
	}
	cout<<s1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}

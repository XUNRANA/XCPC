#include<bits/stdc++.h>
using namespace std;
#define int long long
int i,j,k,n,m,t,a[200010],res;
void solve()
{
	for(i=1,cin>>n;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
    {
		for(j=max(i,j);j<n&&a[j+1]>a[j];j++);
		for(k=max(j,k);k<n&&a[k+1]<a[k]&&a[k+1]>(j==i?-1:a[j-1]);k++);
		for(t=max(k,t);t<n&&a[t+1]>a[t]&&a[t+1]>a[j];t++);
		res+=t-i+1;
	}
	cout<<res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<"1\n";
		return ;
	}
	int f1=1;
	if(a[1]>a[2]) f1=0;
	vector<int>v;
	v.push_back(1);
	for(int i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1]) v.push_back(i);
		else if(a[i]<a[i-1]&&a[i]<a[i+1]) v.push_back(i);
	}
	v.push_back(n);
	int len=v.size(),ans=0;
	for(int i=1;i<len;i++) 
	{
		int m=v[i]-v[i-1]+1;
		ans+=(m+1)*m/2;
	}
	ans-=len-2;
	for(int i=f1;i<len-2;i+=2)
	for(int j=v[i+1]-1;j>=v[i];j--) if(a[j]<a[v[i+1]+1]) ans+=v[i+2]-v[i+1];


	for(int i=f1^1;i<len-2;i+=2)
	for(int j=v[i+1]+1;j<=v[i+2];j++) if(a[j]>a[v[i+1]-1]) ans+=v[i+1]-v[i];
	
	for(int i=f1^1;i<len-3;i+=2)
	if(a[v[i+1]]<a[v[i+2]+1]&&a[v[i+2]]>a[v[i+1]-1]) ans+=(v[i+1]-v[i])*(v[i+3]-v[i+2]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

*/

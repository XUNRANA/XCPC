#include <bits/stdc++.h>
using namespace std;
const int N=3e5+1000;
int a[N],b[N];
int main()
{
	int n;
    long long ans=0;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
    {
		cin>>b[i];
		mp[a[i]^b[i]]++;
	} 
	for(int i=1;i<=n;i++) ans+=mp[a[i]^b[i]];
	cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,ans=1,prime=233317,mod=212370440130137957ll,base=131,a[10010];
string s;
ull hashe(string s)
{
	ull ans=0;
	for(int i=0;i<s.size();i++) ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>s;
		a[i]=hashe(s);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) if(a[i]!=a[i+1]) ans++;
	cout<<ans;
}

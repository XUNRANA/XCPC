#include <bits/stdc++.h>
using namespace std;
int ck(long long x)
{
	string t=to_string(x);
	for(int i=0;i<t.size();i++)
	{
		if(t[i]!=t[t.size()-1-i]) return 0;
	}
	return 1;
}
int main()
{
	long long n,ans=1;
	cin>>n;
	for(long long i=1;i*i*i<=n;i++)
	{
		if(ck(i*i*i)) ans=i*i*i;
	}
	cout<<ans;
}

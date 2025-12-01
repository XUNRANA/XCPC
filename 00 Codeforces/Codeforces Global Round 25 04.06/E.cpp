#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,d;
int is(int l,int r)
{
	for(int i=l;i<l+r-i;i++) if(s[i]!=s[l+r-i]) return 0;
	return 1;
}
void solve()
{
	cin>>s;
	n=s.size();
	if(!is(0,n-1)) cout<<"YES\n1\n"<<s<<"\n";
	else
	{
		d=-1;
		for(int i=1;i<n;i++) 
		if(s[i]!=s[0])
		{
			d=i;
			break;
		}	
		if(d==-1) 
		{
			cout<<"NO\n";
			return ;
		}
		if(!is(0,d)&&!is(d+1,n-1)) cout<<"YES\n2\n"<<s.substr(0,d+1)<<" "<<s.substr(d+1)<<"\n";
		else if(d==1||d==n/2) cout<<"NO\n";
		else cout<<"YES\n2\n"<<s.substr(0,d+2)<<" "<<s.substr(d+2)<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}

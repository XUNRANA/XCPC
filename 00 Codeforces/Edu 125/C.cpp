#include <bits/stdc++.h>
using namespace std;
int n,res;
string s;
void solve()
{
	cin>>n>>s;
	int last=0;
	res=0;
	for(int i=1;i<n;i++)
	{
		if(s[last]=='(')
		{
			last=i+1;
			res++;
			i++;
		}
		else if(s[i]==')')
		{
			last=i+1;
			i++;
			res++;
		}
	}
	cout<<res<<" "<<n-last<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}


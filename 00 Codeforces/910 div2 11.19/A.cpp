#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,c,cnt;
	string s;
	cin>>n>>k>>s;
	c=count(s.begin(),s.end(),'B');
	if(c==k) cout<<"0\n";
	else 
	{
		if(c<k)
		{
			cnt=0;
			for(int i=0;i<n;i++) 
			if(s[i]=='A') 
			{
				cnt++;
				if(cnt+c==k)
				{
					cout<<"1\n";
					cout<<i+1<<" B\n";
				}
			}
		}
		else
		{
			cnt=0;
			for(int i=0;i<n;i++) 
			if(s[i]=='B') 
			{
				cnt++;
				if(c==k+cnt)
				{
					cout<<"1\n";
					cout<<i+1<<" A\n";
				}
			}
		}
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

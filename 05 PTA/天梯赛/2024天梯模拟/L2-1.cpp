#include <bits/stdc++.h>
using namespace std;

void solve()
{
	stack<int>a,b;
	int n;
	cin>>n;
	int mx=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(a.empty()) a.push(x);
		else
		{
			if(x<a.top()) a.push(x);
			else 
			{
				if(b.empty()) b.push(x);
				else if(x>b.top()) b.push(x);
				else
				{
					cnt++;
					mx=max(mx,(int)a.size());
					while(!a.empty()) a.pop();
					while(!b.empty()&&b.top()>x)
					{
						a.push(b.top());
						b.pop();
					}
					a.push(x);
				}
			}
		}
	}
	if(a.size()) 
	{
		cnt++;
		mx=max(mx,(int)a.size());
	}
	if(b.size()) 
	{
		cnt++;
		mx=max(mx,(int)b.size());
	}
	cout<<cnt<<" "<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 

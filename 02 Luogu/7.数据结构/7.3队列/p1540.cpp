#include <bits/stdc++.h>
using namespace std;
int m,n,t,ans;
int main()
{
	cin>>m>>n;
	deque<int>d;
	while(n--)
	{
		cin>>t;
		int f=0;
		for(auto i:d) 
		if(i==t) 
		{
			f=1;
			break;
		}
		if(f==1) continue;
		if(d.size()<m) d.push_back(t),ans++;
		else
		{
			d.pop_front();
			d.push_back(t);
			ans++;
		} 
	}
	cout<<ans;
}

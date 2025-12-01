#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
	int l,r,L,R;
	cin>>l>>r>>L>>R;
	set<int>st;
	for(int i=l;i<=r;i++)
	{
		for(int j=L;j<=R;j++)
		{
			if(j==i-1) st.insert(j);
			if(j==i+1) st.insert(i);
		}
	}
	cout<<max((int)st.size(),1)<<"\n";
 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

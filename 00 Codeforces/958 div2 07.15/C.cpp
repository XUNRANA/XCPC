#include <bits/stdc++.h>
using namespace std;
 
#define int long long
void solve()
{
	int n;
	cin>>n;
	if(log2(n)==(int)log2(n)) 
	{
		cout<<"1\n"<<n<<"\n";
		return ;
	}
	set<int>st;
	for(int i=0;i<=60;i++) 
	if(n>>i&1) st.insert(n-(1<<i));
	st.insert(n);
	cout<<st.size()<<"\n";
	for(auto i:st) cout<<i<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

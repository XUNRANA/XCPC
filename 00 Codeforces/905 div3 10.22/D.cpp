#include <bits/stdc++.h>
using namespace std;
char op;
int l,r;
multiset<int>L,R;
void solve()
{
	cin>>op>>l>>r;
	if(op=='+')
	{
		L.insert(l);
		R.insert(r);
	}
	else 
	{
		L.erase(L.find(l));
		R.erase(R.find(r));
	}
	if(!R.empty()&&!L.empty()&&*R.begin()<*L.rbegin()) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}

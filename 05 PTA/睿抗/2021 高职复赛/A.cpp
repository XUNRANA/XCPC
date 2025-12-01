#include <bits/stdc++.h>
using namespace std;

void solve()
{
	set<int>st;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string s;
		cin>>s;
		x=stoi(s);
//		cin>>x;
		if(!st.count(x)) cout<<"Hello "<<s<<", how are you?\n";
		else cout<<"Hi "<<s<<"! Glad to see you again!\n";
		st.insert(x);
	}	
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

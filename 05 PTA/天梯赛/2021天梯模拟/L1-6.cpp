#include <bits/stdc++.h>
using namespace std;
int fx(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
int ck(int x)
{
	set<int>st;
	for(int i=2;i<=9;i++) st.insert(fx(i*x));
	if(st.size()==1) return *st.begin();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	if(ck(n)) cout<<ck(n)<<"\n";
	else cout<<"NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

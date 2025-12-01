#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,a[N],l[N],r[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int>st;
	st.push(1);
	for(int i=2;i<=n;i++)
	{
		while(st.size()&&a[st.top()]>a[i]) st.pop();
		st.push(i);
		l[i]=st.size()-1;
	}
	while(!st.empty()) st.pop();
	st.push(n);
	for(int i=n-1;i>=1;i--)
	{
		while(st.size()&&a[st.top()]>a[i]) st.pop();
		st.push(i);
		r[i]=st.size()-1;
	}
	for(int i=1;i<=n;i++) cout<<l[i]+r[i]<<" ";
    cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 

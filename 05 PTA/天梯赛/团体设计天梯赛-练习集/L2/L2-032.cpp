#include <bits/stdc++.h>
using namespace std;
int a[1010];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	while(k--)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		stack<int>st;
		int j=1;
		for(int i=1;i<=n;i++)
		{
			if(st.size()>m) break;
			if(a[i]==j) j++;
			else 
			{
				while(!st.empty()&&st.top()==j)
				{
					st.pop();
					j++;
				}
				
				if(st.empty()||a[i]<st.top()) st.push(a[i]);
				else break;
			}
		}
		while(!st.empty()&&st.top()==j)
		{
			st.pop();
			j++;
		}
//		cout<<j<<"\n";
		if(j==n+1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
queue<char>q[110];
void solve()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			q[i].push(x);
		}
	}
	stack<char>st;
	string ans="";
	while(1)
	{
		int op;
		cin>>op;
		if(op==-1) break;
		if(op==0) 
		{
			if(!st.empty())
			{
				ans+=st.top();
				st.pop();
			}
		}
		else
		{
            if(!q[op].empty())
            {
                if(st.size()==s)
    			{
    				ans+=st.top();
    				st.pop();
    			}
			    st.push(q[op].front());
			    q[op].pop();
            }
		}
	}
	cout<<ans<<"\n";
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

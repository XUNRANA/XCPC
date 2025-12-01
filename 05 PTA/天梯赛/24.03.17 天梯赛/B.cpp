#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,j;
void solve()
{
	j=1;
	stack<int>st;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
        st.push(t);
        while(!st.empty()&&st.top()==j)
        {
            st.pop();
            j++;
        }
        
        if((int)st.size()>m)
        {
            cout<<"NO\n";
            return ;
        }
    }
    if(!st.empty()) cout<<"NO\n";
    else cout<<"YES\n";
}

int main()
{
	cin>>n>>m>>k;
	while(k--) solve();
}

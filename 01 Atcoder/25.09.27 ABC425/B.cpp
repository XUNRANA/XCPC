#include <bits/stdc++.h>
using namespace std;

int a[11];
void solve()
{
    int n;
    cin>>n;
    set<int>st;
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]==-1) cnt++;
        else st.insert(a[i]);
    }

    if(cnt==n-st.size())
    {
        cout<<"Yes\n";
        stack<int>b;
        for(int i=1;i<=n;i++) if(!st.count(i)) b.push(i);

        for(int i=1;i<=n;i++)
        if(a[i]==-1)
        {
            cout<<b.top();
            b.pop();
            cout<<" ";
        }
        else cout<<a[i]<<" ";
    }
    else cout<<"No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

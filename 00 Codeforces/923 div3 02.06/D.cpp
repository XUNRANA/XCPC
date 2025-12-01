#include <bits/stdc++.h>
using namespace std;
int n,q,l,r,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>ans;
	cin>>q;
	for(int i=1;i<n;i++) if(a[i]!=a[i+1]) ans.push_back(i);
	while(q--)//¶þ·Ö 
	{
		cin>>l>>r;
		auto k=lower_bound(ans.begin(),ans.end(),l);
		if(k==ans.end()||(*k)>=r) cout<<"-1 -1\n";
		else cout<<*k<<" "<<(*k)+1<<"\n";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;
int n,q,l,r,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>nxt(n+1);
	nxt[n]=n;
	for(int i=n-1;i>=1;i--) nxt[i]= a[i]==a[i+1]? nxt[i+1]:i+1; 
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(nxt[l]>r||(nxt[l]==nxt[r]&&a[l]==a[r])) cout<<"-1 -1\n";
		else cout<<l<<" "<<nxt[l]<<"\n";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
*/

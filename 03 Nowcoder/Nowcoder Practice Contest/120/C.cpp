#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
int i,j,k,n,m,t,a[N+50],f[N+50];
vector<pair<int,int> > op;
int main()
{
    /*
	ios::sync_with_stdio(0);
    cin.tie(0);*/
	cin>>t;
	while(t--)
    {
		map<int,set<int> > mp;
		cin>>n;
		for(i=1;i<=n;i++)
        {
			cin>>a[i];
            f[i]=a[i];
			mp[a[i]].insert(i);
		}
		sort(f+1,f+n+1);
		for(i=1;i<=n;i++)
        {
			if(f[i]+f[n+1-i]!=f[1]+f[n])
            {
				cout<<"NO\n"; 
                goto aaa;
			}
		}
		op={};
		for(i=1;i<=n;i++)
        {
			mp[a[i]].erase(i);
			if(a[i]!=f[i])
            {
				auto w=*mp[f[i]].begin();
				mp[f[i]].erase(w);
				mp[a[i]].insert(w);
				op.push_back({i,w});
				swap(a[i],a[w]);
			}
		}
		cout<<"YES\n"<<op.size()<<'\n';
		for(auto [i,j]:op) cout<<i<<' '<<j<<'\n';
		aaa:;
	}
}
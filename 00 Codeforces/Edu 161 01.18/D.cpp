#include <bits/stdc++.h>
using namespace std;
long long t,n,a[300010],d[300010],cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<pair<int,int>>v;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>d[i];
		for(int i=1;i<=n;i++) v.push_back(make_pair(a[i],d[i]));
		for(int j=1;j<=n;j++)
		{
			cnt=0;
			v.push_back(make_pair(0,0));
			v.insert(v.begin(),make_pair(0,0));
			for(int i=1;i<v.size()-1;i++) if(v[i-1].first+v[i+1].first>v[i].second) v[i].second=0,cnt++;
			if(cnt==0)
			{
				n=n-j+1;
				while(n--) cout<<"0 ";
				break;
			}
			else cout<<cnt<<" ";
			for(auto it=v.begin();it!=v.end();)
			{
				if((*it).second==0) it=v.erase(it);
			    else it++;   
			}
		}
		cout<<"\n";
		//for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
} 


/*
#include <bits/stdc++.h>
using namespace std;
int t,prv,nxt,n,a[300010],d[300010];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=a[n+1]=0;
		for(int i=1;i<=n;i++) cin>>d[i];
		d[0]=d[n+1]=INT_MAX;
		
		set<int>lft,cur;
		for(int i=0;i<n+2;i++) cur.insert(i),lft.insert(i);
		for(int j=1;j<=n;j++)
		{
			set<int>del,ncur;
			for(auto i:cur)
			{
				auto it=lft.find(i);
				if(it==lft.end()) continue;
				prv=*prev(it);
				nxt=*next(it);
				if(a[prv]+a[nxt]>d[i])
				{
					del.insert(i);
					ncur.insert(prv);
					ncur.insert(nxt);
				}
			}
			cout<<del.size()<<" ";
			for(auto it:del) lft.erase(it);
			cur=ncur;
		}
		cout<<"\n";	
	}
}


*/

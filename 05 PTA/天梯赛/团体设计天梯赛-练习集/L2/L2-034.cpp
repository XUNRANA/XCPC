#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	string id;
	string name;
	string tt;
	int t;
}node;
bool cmp(node a1,node a2)
{
	if(a1.tt==a2.tt) return a1.t<a2.t;
	return a1.tt<a2.tt;
}
bool ck(string t)
{
	if(t.size()!=18) return 1;
	for(auto i:t) if(!isdigit(i)) return 1;
	return 0;
}
void solve()
{
	int d,p,t,s;
	cin>>d>>p;
	map<string,int>last;
	vector<pair<string,string>>ans;
	for(int i=1;i<=d;i++)
	{
		cin>>t>>s;
		vector<node>a;
		for(int i1=1;i1<=t;i1++)
		{
			string name,id,ti;
			int f;
			cin>>name>>id>>f>>ti;
			if(ck(id)) continue;
			if(f)
			{
                int fl=0;
                for(auto j1:ans)
                if(j1.second==id)
                {
                    fl=1;
                    break;
                }
                if(!fl) ans.push_back({name,id});
			}
			a.push_back({id,name,ti,i1});
		}
		sort(a.begin(),a.end(),cmp);
		for(int j=0;j<(int)a.size()&&s;j++) 
		{
			if(!last.count(a[j].id)||i-last[a[j].id]>p) 
			{	
				cout<<a[j].name<<" "<<a[j].id<<"\n";
				last[a[j].id]=i;
				s--;
			}
		}
	}
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}


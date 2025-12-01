#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[2020000],dis[2020000],a[5];
vector<pair<int,int>>op,g[2020000];
void solve(){
	int m;
    cin>>m;
    int p=0;
    for(int i=0;i<m;i++){
        int x= 0;
        string s,s2;
        cin>>s>>s2;
        s+=s2;
        reverse(s.begin(),s.end());
        for (char c:s) {
            x=(x*2+c-'0');
        }
        p|=1<<x;
    }
    cout<<p<<"!!!!\n";
    cout<<dis[p]<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=4;i++)cin>>a[i];
	op.push_back({1,a[1]});
	op.push_back({2,a[1]});
	op.push_back({4,a[1]});
	op.push_back({8,a[1]});
	
	op.push_back({3,a[2]});
	op.push_back({12,a[2]});

	op.push_back({5,a[3]});
	op.push_back({10,a[3]});
	
	op.push_back({15,a[4]});
	
	for(int i=1;i<(1<<16);i++)
	{
		//00000000
		//11111111
		
		//00000 00000 00001
//		0001
		
		//00000 00000 00010
//		0010
		//00000 00000 00100
//		0011
		//00000 00000 10000
//		0101		
		for(auto t:op)
		{
			int v=t.first;
			int c=t.second;
			int j=0;
			for(int k=0;k<16;k++){
				if(i>>k&1)
					j|=1<<(k^v);
			}
			j&=(1<<15)-1;
			g[j].push_back({i,c});
		}
	}
	
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,0});
	while(q.size()){
		auto i=q.top();
		int d=i.first;
		int x=i.second;
		q.pop();
		if(st[x])continue;
		st[x]=1;
		for(auto j:g[x]){
			int y=j.first;
			int c=j.second;
			if(dis[y]>d+c){
				dis[y]=d+c;
				q.push({dis[y],y});
			}
		}
	}
	while(t--)
		solve();
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    int k;
    cin>>s>>k;
    if(k>s.size()||k==1) cout<<s<<"\n";
    else
    {
        if(k>26) 
        {
            cout<<"-1\n";
            return ;
        }
        map<char,int>cnt;
        for(auto i:s) cnt[i]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,char>> >pq;
        for(auto i:cnt) pq.push({i.second,i.first});
        queue<pair<int,char>>q;
        string ans="";
        while(!pq.empty())
        {
            int cnt=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans+=ch;
            q.push({cnt-1,ch});
            k--;
            if(k<=0) 
            {
                if(!q.empty())
                {
                    if(q.front().first) pq.push(q.front());
                    q.pop();
                }
            }
        }
        if(ans.size()<s.size()) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

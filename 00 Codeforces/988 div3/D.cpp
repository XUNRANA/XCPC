#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,L;
    cin>>n>>m>>L;
    set<int>a;
    map<int,int>R;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        R[l]=r;
        a.insert(l);
    }
    map<int,vector<int>>g;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a.insert(x);
        g[x].push_back(y);
    }
    priority_queue<int>q;
    int sum=1;
    int cnt=0;
    for(auto l:a)
    {
        if(R.count(l))
        {
            int len=R[l]-l+2;
            while(sum<len)
            {
                if(!q.empty())
                {
                    sum+=q.top();
                    q.pop();    
                    cnt++;
                }
                else
                {
                    cout<<"-1\n";
                    return ;
                }
            }
        }
        else
        {
            for(auto x:g[l]) q.push(x);
        }
    }
    cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

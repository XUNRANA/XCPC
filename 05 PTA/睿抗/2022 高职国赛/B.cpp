#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
struct node
{
    string id;
    int st;
    string date;
}a[100010];
bool cmp(node a1,node a2)
{
    
    if(a1.date==a2.date) 
    {
        if(a1.st==a2.st) return a1.id<a2.id;
        return a1.st<a2.st;
    }
    else return a1.date<a2.date;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].id>>a[i].st>>a[i].date;
    sort(a+1,a+1+m,cmp);
    
    queue<int>q1;
    queue<string>q2;
    map<string,int>mp;
    for(int i=1;i<=n;i++) q1.push(i);



    // for(int i=1;i<=m;i++) cout<<a[i].id<<" "<<a[i].st<<" "<<a[i].date<<"\n";
    


    for(int i=1;i<=m;i++)
    {
        // cout<<i<<"\n";
        if(a[i].st)
        {
            if(q1.size())
            {
                mp[a[i].id]=q1.front();
                cout<<a[i].id<<" - "<<q1.front()<<"\n";
                q1.pop();
            }
            else 
            {
                mp[a[i].id]=-1;//need
                q2.push(a[i].id);
            }
        }
        else
        {
            if(mp[a[i].id]==-1)//need 
            {
                cout<<a[i].id<<" - NONE\n";
                mp[a[i].id]=-2;
                // erase;
            }
            else 
            {
                //erase
                while(q2.size()&&mp[q2.front()]==-2) q2.pop();
                if(q2.size())
                {
                    cout<<q2.front()<<" - "<<mp[a[i].id]<<"\n";   
                    mp[q2.front()]=mp[a[i].id];
                    q2.pop();
                }
                else 
                {
                    q1.push(mp[a[i].id]);
                }
            }
        }
    }
    int f=0;
    while(!q1.empty()) 
    {
        if(f) cout<<" ";
        cout<<q1.front();
        f=1;
        q1.pop();

    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

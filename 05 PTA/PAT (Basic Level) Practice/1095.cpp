#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    string id;
    string rk;//级别
    string k;//考场编号
    string d;//考试日期
    string b;//考生编号
    int c;
}st[10010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>st[i].id>>st[i].c;
        st[i].rk=st[i].id.substr(0,1);
        st[i].k=st[i].id.substr(1,3);
        st[i].d=st[i].id.substr(4,6);
        st[i].b=st[i].id.substr(10,3);
    }
    for(int j=1;j<=m;j++)
    {
        int op;
        string x;
        cin>>op>>x;
        cout<<"Case "<<j<<": "<<op<<" "<<x<<"\n";
        if(op==1)
        {
            vector<pair<int,string>>ans;
            for(int i=1;i<=n;i++) if(st[i].rk==x) ans.push_back({-st[i].c,st[i].id});
            sort(ans.begin(),ans.end());
            
            if(ans.size()) for(auto i:ans) cout<<i.second<<" "<<-i.first<<"\n";
            else cout<<"NA\n";
        }
        else if(op==2)
        {
            int cc=0,ss=0;
            for(int i=1;i<=n;i++) 
            {
                if(st[i].k==x) 
                {
                    ss+=st[i].c;
                    cc++;
                }
            }

            if(!cc) cout<<"NA\n";
            else cout<<cc<<" "<<ss<<"\n";
        }
        else
        {

            map<string,int>mp;
            for(int i=1;i<=n;i++) 
            {
                if(st[i].d==x)
                {
                    mp[st[i].k]++;
                }
            }

            vector<pair<int,string>>ans;
            for(auto i:mp) ans.push_back({-i.second,i.first});
            sort(ans.begin(),ans.end());
            if(ans.size()) for(auto i:ans) cout<<i.second<<" "<<-i.first<<"\n";
            else cout<<"NA\n";
        }

    }

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

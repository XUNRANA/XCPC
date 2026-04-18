#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1) 
        {
            string s1;
            cin>>s1;
            vector<int>ans;
            for(int i=0;i+s1.size()<=s.size();i++) if(s.substr(i,s1.size())==s1) ans.push_back(i);
            if(ans.size()==0) cout<<"-1\n";
            else 
            {
                if(ans.size()==1) cout<<ans[0]<<"\n";
                else if(ans.size()<=3) for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
                else cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
            }
        }
        else if(op==2)
        {
            int p;
            string s2;
            cin>>p>>s2;
            if(p==s.size()) s+=s2;
            else 
            {
                string xxxx=s.substr(0,p);
                string yyyy=s.substr(p);
                s=xxxx+s2+yyyy;
            }
            cout<<s<<"\n";
        }
        else
        {
            int l,r;
            cin>>l>>r;
            string p=s.substr(l,r-l+1);
            reverse(p.begin(),p.end());
            string xxxx=s.substr(0,l);
            string yyyy=s.substr(r+1);
            s=xxxx+p+yyyy;
            cout<<s<<"\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
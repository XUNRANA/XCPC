#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int s,k;
    cin>>s>>k;
    if(s%k==0) cout<<k<<"\n";
    else
    {
        if(s>=k*(k-2)) cout<<max(k-2,1)<<"\n";
        else
        {
            queue<array<int,3>>q;
            vector<int>vt(s+1,0);
            q.push({0,k+1,-1});
            int now=0;
            while(!q.empty())
            {
                int pos=q.front()[0];
                int kk=q.front()[1];
                int d=q.front()[2];
                q.pop();
                if(kk!=1) kk--;
                d=-d;
                if(kk!=now)
                {
                    now=kk;
                    for(int i=0;i<=s;i++) vt[i]=0;
                }
                for(int i=1;;i++)
                {
                    int nxt=pos+d*kk*i;
                    if(nxt<0||nxt>s) break;
                    if(nxt==s)
                    {
                        cout<<kk<<"\n";
                        return ;
                    }
                    if(!vt[nxt]) 
                    {
                        q.push({nxt,kk,d});
                        vt[nxt]=1;
                    }
                }
            }
        }
    }
    

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

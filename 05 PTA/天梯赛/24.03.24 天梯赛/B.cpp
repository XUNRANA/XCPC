#include <bits/stdc++.h>
using namespace std;
char a[110][1010];
int b[110];
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s;
    getchar();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
        getchar();
    }
    for(int i=1;i<=n;i++) b[i]=1;

    vector<char>ans;
    stack<char>st;
    while(1)
    {
        cin>>t;
       // cout<<t<<" "<<st.size()<<" "<<ans.size()<<"\n";
        if(t==-1) break;

        if(t==0)
        {
            if(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            continue;
        }
        


        if(b[t]!=m+1)
        {
        	if((int)st.size()==s)
	        {
	            ans.push_back(st.top());
	            st.pop();
	        }
            st.push(a[t][b[t]]);
            b[t]++;
        }
    }
    
    for(int i=0;i<(int)ans.size();i++) cout<<char(ans[i]);
}

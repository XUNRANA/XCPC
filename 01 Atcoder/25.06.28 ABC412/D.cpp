#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    cin>>n>>m;
    multiset<array<int,2>>st;
    for(int i=1;i<=m;i++) 
    {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        st.insert({a,b});
    }

    int res=100;

    for(int i=1;i<(1<<n);i++)
    {
        vector<int>c,d;
        for(int j=0;j<n;j++) 
        if(i>>j&1) c.push_back(j+1);
        else d.push_back(j+1);
        
        if(c.size()==n)
        {
            do
            {
                multiset<array<int,2>>st1=st;
                int l=c.back();
                int ans=0;
                for(auto i1:c)
                {
                    if(!st1.count({min(l,i1),max(l,i1)})) 
                    {
                        st1.insert({min(l,i1),max(l,i1)});      
                        ans++; 
                    }  
                    l=i1;   
                }
                ans+=st1.size()-n;
                res=min(res,ans);
                // cout<<ans<<"?\n";
            }while(next_permutation(c.begin(),c.end()));
        }
        else if(c.size()>=3&&d.size()>=3)
        {

            do
            {
                vector<int>d1=d;
                do
                {
                    multiset<array<int,2>>st1=st;
                    int l=c.back();
                    int ans=0;
                    for(auto i1:c)
                    {
                        if(!st1.count({min(l,i1),max(l,i1)})) 
                        {
                            st1.insert({min(l,i1),max(l,i1)});      
                            ans++; 
                        }  
                        l=i1;   
                    }

                    l=d1.back();
                    for(auto i1:d1)
                    {
                        if(!st1.count({min(l,i1),max(l,i1)})) 
                        {
                            st1.insert({min(l,i1),max(l,i1)});      
                            ans++; 
                        }  
                        l=i1;   
                    }
                    
                    ans+=st1.size()-n;
                    res=min(res,ans);



                    
                    
                } while (next_permutation(d1.begin(),d1.end()));
                
                
            }while(next_permutation(c.begin(),c.end()));
        }
    }
    cout<<res<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}

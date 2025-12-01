#include <bits/stdc++.h>
using namespace std;
deque<int>l,r;
void balance()
{
    while(l.size()<r.size())
    {
        int t=r.front();
        r.pop_front();
        l.push_back(t);
    }
    while(l.size()>r.size()+1)
    {
        int t=l.back();
        l.pop_back();
        r.push_front(t);
    }
}
void print(deque<int>dq)
{
    while(dq.size())
    {
        cout<<dq.front();
        dq.pop_front();
    }
}
void query()
{
    balance();
    cout<<l.back()<<"\n";
    l.pop_back();
    balance();
}
void solve()
{
    int q,op,x;
    cin>>q;
    l.clear();
    r.clear();
    while(q--)
    {
        cin>>op;
        if(op==3) query();
        else
        {
            cin>>x;
            if(op==1) l.push_front(x);
            else r.push_back(x);
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

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a=0,c=0,e=0,p=0,t=0;
        string s;
        cin>>n>>s;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case 'A':a++;break;
                case 'C':c++;break;
                case 'E':e++;break;
                case 'P':p++;break;
                case 'T':t++;break;
            }
        }
        cout<<min({a,c/2,e,p,t})<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int res=0; bool f=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) res=res*10+(ch^'0'),ch=getchar();
    return f?-res:res;
}
int k,b,c,v;
inline int get(int l,int r) {
    if(r<b) return 0;
    int ok=0;
    if(l<=b&&b<=r) ok=1;
    return ((r-b)/k)-max(0ll,((l-1-b)/k))+ok;
}  // l<= kx+b <=r
signed main() {
    int TT=read();
    while(TT--) {
        k=read(),b=read(),c=read(),v=read();
        int ans=0,now=0;
        for(int i=59;i>=0;i--) {
            int x=(v>>i)&1,y=(c>>i)&1;
            if(x) {
                // （kx+b） xor c 这一位是 0 则后面随便
                ans+=get(now+(y<<i),now+(y<<i)+(1ll<<i)-1);
            }
            now+=((x^y)<<i);
        }
        c^=v; // 恰好取等
        ans+=get(c,c);
        printf("%lld\n",ans);
    }
    return 0;
}

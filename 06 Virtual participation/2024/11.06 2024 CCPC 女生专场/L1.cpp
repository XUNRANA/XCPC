#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
	
    int a,b,c,d;
	cin >> a >> b >> c >> d;
    auto check = [&](int x,int y)->int{
        int need_bc = (2*(x+y-2)-4)/2;
        int need_d = (x-2)*(y-2);
        if(need_d<=d && need_bc<=c && need_bc<=b){
            return need_bc*2 + 4 + need_d;
        }else{
            return -1;
        }
    };

    int ans = 0;
    if(a < 4) {
        return cout << "0\n", void();
    }else{
        int xl = (b + c + 4) / 2;
        for(int x = 2; x <= xl ; x ++) {
            int l = 2, r = xl;
            while(l <= r) {
                int mid = l + r >> 1;
                int ret = check(x,mid);
                if(ret == -1) r = mid - 1;
                else{
                    l = mid + 1;
                    cout<<x<<" "<<mid<<"??????????\n";
                    cout<<ret<<"?\n";
                    ans = max(ans,ret);
                }
            }
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

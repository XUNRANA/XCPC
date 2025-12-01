#include<bits/stdc++.h>
using namespace std;
struct node {
    char c;
    int tag;
    node *pre, *nxt, *dpre, *dnxt;
    node () {c='?';tag=-1;pre=NULL;nxt=NULL;dpre=NULL;dnxt=NULL;}
};
int n;
vector<node*> g[30][30][30];
node *head = new node(), *tail = new node();
string s;

int ctag(int i, int j, int k) {
    return i * 26 * 26 + j * 26 + k;
}

void ptag(int i, int j, int k, node *a, node *b, node *c) {
    int tag = ctag(i, j, k);
    a->tag = b->tag = c->tag = tag;
    return ;
}

bool check(int i, int j, int k, node *a, node *b, node *c) {
    int tag = ctag(i, j, k);
    if(a->tag == tag || b->tag == tag || c->tag == tag) return false;
    if(a->c == (char)('a' + i) && b->c == (char)('a' + j) && c->c == (char)('a' + k)) return true;
    return false;
}

void solve() {
    cin >> n;
    
    if (n <= 2) {
        cout << 0 << endl;
        cout << "aaa" << endl;
        return;
    }
    
    cin >> s;

    head->nxt = tail;
    tail->pre = head;


    for(int i = 0; i < s.size(); i ++ ) {
        node *p = new node();
        p->c = s[i];
        p->pre = tail->pre;
        p->nxt = tail;
        tail->pre->nxt = p;
        tail->pre = p;
        if(i + 2 < s.size()) {
            g[s[i] - 'a'][s[i + 1] - 'a'][s[i + 2] - 'a'].push_back(p);
        }
    }

    int ans = 0;
    string str;


    for(int i = 0; i < 26; i ++ ) {
        for(int j = 0; j < 26; j ++ ) {
            for(int k = 0; k < 26; k ++ ) {
                int res = 0;
                for(auto x : g[i][j][k]) {
                    auto p = x, q = x->nxt;
                    int tag = ctag(i, j, k);
                    while(p != head && q != tail && p->tag != tag && q->tag != tag) {
                        if(check(i, j, k, p, q, q->nxt)) {
                            auto tp = p, tq = q->nxt;
                            ptag(i, j, k, p, q, q->nxt);
                            p = tp->pre->tag == tag ? tp->dpre : tp->pre;
                            q = tq->nxt;
                            q->dpre = p;
                            res ++ ;
                        }else if(check(i, j, k, p->pre->tag == tag ? p->dpre : p->pre, p, q)) {
                            auto tp = p->pre->tag == tag ? p->dpre : p->pre, tq = q;
                            ptag(i, j, k, p->pre->tag == tag ? p->dpre : p->pre, p, q);
                            p = tp->pre->tag == tag ? tp->dpre : tp->pre;
                            q = tq->nxt;
                            q->dpre = p;
                            res ++ ;
                        } else {
                            q->dpre = p;
                            break;
                        }
                    }
                }
                if(res > ans) {
                    ans = res;
                    str = "";
                    str.push_back(i + 'a');
                    str.push_back(j + 'a');
                    str.push_back(k + 'a');
                }
            }
        }
    }

    cout << ans << "\n" << str << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i ++ ) {
        solve();
    }
}

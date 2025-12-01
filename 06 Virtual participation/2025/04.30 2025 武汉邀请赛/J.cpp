#include <bits/stdc++.h>
using namespace std;

struct State {
    int len, link;
    map<char, int> next;
    long long cnt;
    long long sum_end;
};

struct TrieNode {
    map<char, TrieNode*> children;
    long long contribution;
    TrieNode() : contribution(0) {}
};

class Solution {
public:
    vector<State> sam;
    int size;
    int last;

    void sam_init() {
        sam.clear();
        sam.push_back({0, -1, {}, 0, 0});
        last = 0;
        size = 1;
    }

    void sam_extend(char c, int pos) {
        int curr = size++;
        sam.push_back({sam[last].len + 1, -1, {}, 1, pos});
        int p = last;
        while (p != -1 && !sam[p].next.count(c)) {
            sam[p].next[c] = curr;
            p = sam[p].link;
        }
        if (p == -1) {
            sam[curr].link = 0;
        } else {
            int q = sam[p].next[c];
            if (sam[p].len + 1 == sam[q].len) {
                sam[curr].link = q;
            } else {
                int clone = size++;
                sam.push_back(sam[q]);
                sam[clone].len = sam[p].len + 1;
                sam[clone].cnt = 0;
                sam[clone].sum_end = 0;
                while (p != -1 && sam[p].next[c] == q) {
                    sam[p].next[c] = clone;
                    p = sam[p].link;
                }
                sam[q].link = clone;
                sam[curr].link = clone;
            }
        }
        last = curr;
    }

    void build_sam(const string& s) {
        sam_init();
        for (int i = 0; i < s.size(); ++i) {
            sam_extend(s[i], i);
        }
        vector<int> order(size);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return sam[a].len > sam[b].len;
        });
        for (int u : order) {
            if (sam[u].link != -1) {
                sam[sam[u].link].cnt += sam[u].cnt;
                sam[sam[u].link].sum_end += sam[u].sum_end;
            }
        }
    }

    long long query_substring(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!sam[u].next.count(c)) return 0;
            u = sam[u].next[c];
        }
        int m = s.size();
        if (sam[u].len != m || (sam[u].link != -1 && sam[sam[u].link].len >= m)) {
            return 0;
        }
        return sam[u].cnt * (sam[0].len + 1) - sam[u].sum_end;
    }

    vector<long long> solve(string& s, vector<tuple<int, int, int>>& queries) {
        int n = s.size();
        reverse(s.begin(), s.end());
        build_sam(s);

        vector<tuple<string, int, long long>> processed;
        for (auto& [l, r, idx] : queries) {
            int m = r - l + 1;
            string sub = s.substr(n - 1 - r, m);
            long long x = query_substring(sub);
            processed.emplace_back(sub, idx, x);
        }

        sort(processed.begin(), processed.end(), [](const auto& a, const auto& b) {
            return get<0>(a).size() > get<0>(b).size();
        });

        TrieNode* root = new TrieNode();
        vector<long long> res(queries.size(), 0);

        for (auto& [sub, idx, x] : processed) {
            TrieNode* node = root;
            vector<TrieNode*> path;
            bool exists = true;
            for (char c : sub) {
                path.push_back(node);
                if (node->children.find(c) == node->children.end()) {
                    exists = false;
                    break;
                }
                node = node->children[c];
            }
            if (exists) {
                res[idx] = 0;
                continue;
            }

            node = root;
            for (char c : sub) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }

            long long sum_children = 0;
            for (auto& [ch, child] : node->children) {
                sum_children += child->contribution;
            }
            node->contribution = x - sum_children;
            res[idx] = node->contribution;
        }

        vector<long long> ans(queries.size());
        long long total = 0;
        for (int i = 0; i < queries.size(); ++i) {
            total += res[i];
            ans[i] = total;
        }

        vector<long long> final_ans(queries.size());
        for (auto& [sub, idx, x] : processed) {
            final_ans[idx] = ans[idx];
        }

        return final_ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int q;
        cin >> q;
        vector<tuple<int, int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            queries[i] = {l, r, i};
        }

        Solution sol;
        vector<long long> ans = sol.solve(s, queries);

        for (int i = 0; i < q; ++i) {
            cout << ans[i] << (i == q-1 ? '\n' : ' ');
        }
    }

    return 0;
}
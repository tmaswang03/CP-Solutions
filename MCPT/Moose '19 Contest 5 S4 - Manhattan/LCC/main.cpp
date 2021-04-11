#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

set<pll> gym_x; map<ll, unordered_set<ll>> gym_y;
set<pll> groc_x; map<ll, unordered_set<ll>> groc_y;
multimap<ll, pair<ll, bool>> pts;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//  #endif

    ll N, M; cin >> N >> M;
    for (ll i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        pts.insert({ x, { y, true } });
    }
    for (ll i = 0; i < M; i++) {
        ll x, y; cin >> x >> y;
        pts.insert({ x, { y, false } });
    }

    ll d = LL_INF;
    for (auto p : pts) {
        ll x = p.first, y = p.second.first;
        bool is_gym = p.second.second;
        if (is_gym) {
            if (d != LL_INF) {
                auto end_x = groc_x.upper_bound({ x - d, 0 });
                for (auto it = groc_x.begin(); it != end_x; ++it) {
                    ll rx = (*it).first, ry = (*it).second;
                    groc_y[ry].erase(rx);
                }
                groc_x.erase(groc_x.begin(), end_x);
            }
            auto begin_y = groc_y.lower_bound(y - d);
            auto end_y = groc_y.upper_bound(y + d);
            for (auto it = begin_y; it != end_y; ++it) {
                ll cy = (*it).first;
                for (ll cx: (*it).second) {
                    d = min(d, abs(cx - x) + abs(cy - y));
                }
            }
            gym_x.insert({ x, y });
            gym_y[y].insert(x);
        }
        else {
            if (d != LL_INF) {
                auto end_x = gym_x.upper_bound({ x - d, 0 });
                for (auto it = gym_x.begin(); it != end_x; ++it) {
                    ll rx = (*it).first, ry = (*it).second;
                    gym_y[ry].erase(rx);
                }
                gym_x.erase(gym_x.begin(), end_x);
            }
            auto begin_y = gym_y.lower_bound(y - d);
            auto end_y = gym_y.upper_bound(y + d);
            for (auto it = begin_y; it != end_y; ++it) {
                ll cy = (*it).first;
                for (ll cx: (*it).second) {
                    d = min(d, abs(cx - x) + abs(cy - y));
                }
            }
            groc_x.insert({ x, y });
            groc_y[y].insert(x);
        }
    }
    cout << d / 2 + d % 2 << '\n';

    return 0;
}

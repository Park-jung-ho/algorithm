#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <utility>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int num, x, y, z, n;

struct info {
    int num;
    int mult;
    int added;

    info(int nn, int mm, int aa): num(nn), mult(mm), added(aa) {}
};

void solve() {
    cin >> n;
    vector<info> rank;
    for(int i = 0; i < n; i++) {
        cin >> num >> x >> y >> z;
        rank.push_back(info(num, x * y * z, x + y + z));
        // cout << rank[i] << " \n"[i==n-1];
    }


    sort(rank.begin(), rank.end(), [](info p1, info p2) {
        if(p1.mult == p2.mult) {
            if(p1.added == p2.added) {
                return p1.num < p2.num;
            }
            return p1.added < p2.added;
        }
        return p1.mult < p2.mult;
    });

    // for(int i = 0; i < n; i++) {
    //     cout << rank[i].num <<  rank[i].mult << rank[i].added;
    // }

    for(int i = 0; i < 3; i++) {
        cout << rank[i].num << " \n"[i == 2];
    }
}

int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
    solve();
} 
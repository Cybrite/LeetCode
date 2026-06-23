class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1), down(m + 1);

        // length = 2
        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;      // prev < x
            down[x] = m - x;    // prev > x
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> nup(m + 1), ndown(m + 1);

            // nup[x] = sum(down[p]) for p < x
            long long pref = 0;
            for (int x = 1; x <= m; x++) {
                nup[x] = pref;
                pref = (pref + down[x]) % MOD;
            }

            // ndown[x] = sum(up[p]) for p > x
            long long suff = 0;
            for (int x = m; x >= 1; x--) {
                ndown[x] = suff;
                suff = (suff + up[x]) % MOD;
            }

            up = move(nup);
            down = move(ndown);
        }

        long long ans = 0;
        for (int x = 1; x <= m; x++) {
            ans = (ans + up[x] + down[x]) % MOD;
        }

        return (int)ans;
    }
};
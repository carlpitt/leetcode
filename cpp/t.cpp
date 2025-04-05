class Solution {
    public:
        int maximumGain(string s, int x, int y) {
            int dir = 1, st = 0, en = s.size();
            if (x < y) {
                dir = -1;
                st = en - 1;
                en = -1;
                swap(x, y);
            }

            int ac = 0, bc = 0, res = 0;
            for (int i = st; i != en; i += dir) {
                if (s[i] == 'a') {
                    ac++;
                } else if (s[i] == 'b') {
                    if (ac > 0) {
                        res += x;
                        ac--;
                    } else {
                        bc++;
                    }
                } else {
                    res += y * min(ac, bc);
                    ac = 0, bc = 0;
                }
            }

            res += y * min(ac, bc);
            return res;
        }
};

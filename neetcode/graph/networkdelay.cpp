// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, -1);
        dist[0] = 0;
        dist[k] = 0;
        for (int i =0; i < n; i++) {
            for (int j=0; j <times.size(); j++) {
                int u = times[j][0] ;
                int v = times[j][1] ;
                int w = times[j][2];
                //cout << u <<" " <<v << " " <<dist[u] << endl;

                if (dist[u] != -1 && (dist[u] + w < dist[v] || dist[v] == -1)) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        int ans = 0;
        for (int i=0; i < n + 1; i ++) {
            if (dist[i] == -1) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;

    }
};
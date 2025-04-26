class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<float, vector<int>> m;

        for(vector<int>& v: points) {
            float dis = sqrt(pow(v[0], 2)+ pow(v[1], 2));
            m.insert({dis, v});
            //cout << dis << " " <<v[0] << " " <<v[1] << endl;
        }
        points.clear();
        for (auto [key, value]: m) {
            //cout << key << " " <<value[0] << " " <<value[1] << endl;
            points.push_back(value);
            k--;
            if (k == 0) break;
        }

        return points;

    }
};
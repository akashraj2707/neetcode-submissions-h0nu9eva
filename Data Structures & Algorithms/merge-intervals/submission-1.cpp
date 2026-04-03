class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sp,ep;

        sort(intervals.begin(),intervals.end());

        int i=0;
        vector<vector<int>> res;

        sp = intervals[i][0];
        ep = intervals[i][1];

        i++;
        int x,y;
        while(i<intervals.size()){
            x = intervals[i][0];
            y = intervals[i][1];

            if( x <= ep){
                ep = max(ep, y);
            }else {
                res.push_back({sp,ep});
                sp=x;
                ep=y;
            }
            i++;
        }

        res.push_back({sp,ep});

        return res;

    }
};

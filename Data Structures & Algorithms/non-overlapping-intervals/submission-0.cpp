class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans=0;

        int sp,ep;

        sort(intervals.begin(),intervals.end());
        sp= intervals[0][1];
        ep= intervals[0][1];

            
        int i=1;
        int x,y;
        while(i<intervals.size()){
            x = intervals[i][0];
            y = intervals[i][1];

            // cout<< sp << ' '<< ep<< ' '<< x << ' '<< y<< '\n';

            if(x < ep){
                if(ep > y){
                    sp = x;
                    ep = y;
                }
                ans++;
            }else {
                sp = x;
                ep = y;
            }
            i++;
        }

        return ans;
    }
};

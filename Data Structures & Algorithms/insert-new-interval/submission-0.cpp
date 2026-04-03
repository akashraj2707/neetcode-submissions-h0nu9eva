class Solution {
public:

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        vector<vector<int>> res;

        int i=0;
        int x,y;
       
        int sp,ep;
        sp=intervals[i][0];
        ep=intervals[i][1];

        i++;    
        while(i<intervals.size()){
           
            x=intervals[i][0];
            y=intervals[i][1];  

            if(x <= ep){
               ep = max(ep,y); 
            } else {
                res.push_back({sp,ep});

                sp= x;
                ep= y;
            }
            i++;
        }

        res.push_back({sp,ep});

        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        return mergeIntervals(intervals);
    }
};

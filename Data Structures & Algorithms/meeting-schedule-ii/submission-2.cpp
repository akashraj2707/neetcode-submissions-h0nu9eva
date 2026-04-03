/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    static bool compare(Interval i1, Interval i2){
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);

        int sp,ep;
        sp = intervals[0].start;
        ep = intervals[0].end;

        int i=1;
        int x,y;
        int ans=1, cur =1;
        
        priority_queue<int,vector<int>,greater<int>> pq;

        pq.push(ep);
        while(i< intervals.size()){
            x = intervals[i].start;
            y = intervals[i].end;

            if( x < pq.top()){
                pq.push(y);
            }else {
                while(pq.size()>0 && pq.top() <= x){
                    pq.pop();
                }

                pq.push(y);
               
            }
            cur = pq.size();
            ans = max(ans, cur);
            i++;
        }

        return ans;
    }
};

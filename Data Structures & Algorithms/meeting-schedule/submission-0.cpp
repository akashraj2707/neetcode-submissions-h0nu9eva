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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);

        int sp,ep;
        sp = intervals[0].start;
        ep = intervals[0].end;

        int i=1;
        int x,y;
        while(i<intervals.size()){
            x = intervals[i].start;
            y = intervals[i].end;


            if(x < ep){
                return false;
            } else {
                sp = x;
                ep = y;
            }

            i++;

        }

        return true;
    }
};

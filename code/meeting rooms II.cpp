/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });
        vector<Interval> rooms;
        for(auto & in: intervals){
            bool flag = false;
            for(int i=0; i<rooms.size(); i++){
                if(rooms[i].end <= in.start){
                    rooms[i] = in;
                    flag = true;
                    break;
                }
            }
            if(!flag) rooms.push_back(in);
        }
        return rooms.size();
    }
};
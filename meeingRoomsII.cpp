/*
Meeting Rooms II

Solution
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/

class Solution {
public:

    void addIfDoesntExist(int val, int v, map<int, vector<int>> &target){
        if(target.find(val)==target.end()){
            vector<int> tmp;
            tmp.push_back(v);
            target.insert( std::pair<int, vector<int>>(val, tmp) );
        }
        else{
            target[val].push_back(v);
        }
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, vector<int>> intvl;
        vector<int> track;
        
        if(intervals.size()==0)
            return 0;
        
        // order intervals
        for(vector<int> &v : intervals){
            addIfDoesntExist(v[0], v[1], intvl);
        }        
        
        // sort vectors}
        for(auto &mi : intvl)
            sort(mi.second.begin(), mi.second.end());
        
        int levels=0;
        for(auto &mi : intvl){       
            
            // remove the items that already ended at this start time
            int i=0;
            bool somethingToDelete=false;
            for(i=0;i<track.size();i++){
                //cout << "  " << mi.first << ">=" << track[i] << std::endl;
                if(mi.first>=track[i]){
                    i++;
                    somethingToDelete=true;
                    break;
                }
            }
                       
            if(somethingToDelete)                
                track.erase(track.begin(), track.begin()+i);            
            
            // how many end times for this start time?
            for(int &endT : mi.second){
                track.push_back(endT);
                sort(track.begin(), track.end());
            }

            if(track.size()>levels)
                levels=track.size();
            
        }
        
        return levels;
    }
};
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Interval {
    int startTime;
    int endTime;
    int room; // added to store the assigned room number
};

// sorts meetings by start time in ascending order
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.startTime < b.startTime;
}

// comparator for the priority queue, orders by the earliest end time
struct IntervalComparator {
    bool operator()(const Interval& a, const Interval& b) const {
        return a.endTime > b.endTime;
    }
};

// calculates the minimum number of meeting rooms required
int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) {
        return 0; // no meetings = no rooms needed
    }

    // sorts the intervals by start time in increasing order
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // priority queue to track the end times of meetings in rooms
    priority_queue<Interval, vector<Interval>, IntervalComparator> endTimes;

    // allocates the first room and pushes it into the priority queue (the earliest meeting)
    int roomCount = 1;
    intervals[0].room = roomCount;
    endTimes.push(intervals[0]);

    // iterates through remaining meetings
    for (int i = 1; i < intervals.size(); ++i) {
        Interval currentMeeting = intervals[i];
        Interval latestEndMeeting = endTimes.top();
        
        // checks if the room can be re-used (current meeting starts after or when the previous meeting ends)
        if (currentMeeting.startTime >= latestEndMeeting.endTime) {
            endTimes.pop(); // re-uses the room
            currentMeeting.room = latestEndMeeting.room;
        }
        else {
            // allocates a new room
            roomCount++;
            currentMeeting.room = roomCount;
        }

        endTimes.push(currentMeeting); // adds the current meeting to the priority queue
        intervals[i] = currentMeeting; // updates the current meeting with its assigned room
    }
    
    return roomCount;
}

int main() {
    vector<Interval> intervals = {
        {930, 1030},
        {945, 1050},
        {900, 1000},
        {1030, 1130},
        {1100, 1200},
        {1000, 1100}
    };

    int minRooms = minMeetingRooms(intervals);
    cout << "minimum number of meeting rooms required: " << minRooms << endl;

    // prints the info of the meetings
    for (const Interval& interval : intervals) {
        cout << "meeting: " << interval.startTime << " - " << interval.endTime << " assigned to room " << interval.room << endl;
    }

    return 0;

    /* Output: minimum number of meeting rooms required: 3
               meeting: 900 - 1000 assigned to room 1
               meeting: 930 - 1030 assigned to room 2
               meeting: 945 - 1050 assigned to room 3
               meeting: 1000 - 1100 assigned to room 1
               meeting: 1030 - 1130 assigned to room 2
               meeting: 1100 - 1200 assigned to room 3 
               
       Explanation: the function calculates the minimum number of meeting rooms required to schedule all the given meetings without conflicts.

                    each meeting is assigned to the earliest available room or a new room if no existing room is free.

                    the output includes:
                        the total number of rooms used (3 in this case).
                        a detailed assignment of each meeting to its respective room.

                    the solution efficiently tracks room usage using a priority queue based on meeting end times, ensuring minimal room allocation. 
                    the output aligns with the given meeting schedule, showing room re-use wherever possible. */
}
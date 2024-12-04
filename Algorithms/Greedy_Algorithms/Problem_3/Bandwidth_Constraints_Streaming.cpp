#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Packet {
    int size; // size of packet in bits
    int time; // time required to send the packet in seconds
};

// sorts packets based on the ratio of size to time
bool compare(Packet a, Packet b) {
    return (a.size * b.time) > (b.size * a.time); // sorts packets in descending order of size/time ratio
}

bool existsValidPlanning(vector<Packet>& packets, int restriction) {
    // (size * time)
    sort(packets.begin(), packets.end(), compare);

    int totalBitsSent = 0;

    for (const Packet& packet : packets) {
        // calculates the time at which the current packet would finish transmission
        int finishTime = totalBitsSent / restriction + packet.time;

        // checks if sending the current packet would exceed the bandwidth constraint
        if (totalBitsSent + packet.size > restriction * finishTime) {
            return false;
        }

        // updates the total bits sent
        totalBitsSent += packet.size;
    }

    return true; // all packets were sent without violating the bandwidth constraint
}

int main() {
    vector<Packet> packets = { {2000, 1}, {6000, 2}, {2000, 1}} ;
    int restriction = 5000; // in bits per second

    if (existsValidPlanning(packets, restriction)) {
        cout << "a valid planning exists";
    }
    else {
        cout << "no valid planning exists";
    }
    cout << endl;

    return 0;

    /* Output: a valid planning exists 

       Explanation: at any point in time, the total number of bits sent cannot grow too quickly. 
                    specifically, the total bits sent must always stay below the amount allowed by the bandwidth restriction. 

                    this allowed amount is calculated as: 
                        allowed bits = restriction * time elapsed

                    packet 1: Size = 2000 bits, Time = 1 second
                    packet 2: Size = 6000 bits, Time = 2 seconds
                    packet 3: Size = 2000 bits, Time = 1 second

                    the packets are sorted by their efficiency (size/time):

                        packet 2: 6000 / 2 = 3000 bits per second
                        packet 1: 2000 / 1 = 2000 bits per second
                        packet 3: 2000 / 1 = 2000 bits per second

                    the sorted order is packet 2, packet 1, packet 3.

     ----------------------------------------------------------------------------------------------------

                    start with packet 2 (size = 6000 bits, time = 2 seconds):
                        initially, totalBitsSent = 0.
                        the time required to send packet 2 is 2 seconds.
                        the maximum allowable bits at time t = 2 are:

                            max bits = restriction * t = 5000 * 2 = 10000 bits

                        sending packet 2 (6000 bits) is within the limit:

                            totalBitsSent = 6000 <= 10000

     ----------------------------------------------------------------------------------------------------
                            
                    send packet 1 (size = 2000 bits, time = 1 second):
                        totalBitsSent = 6000 after packet 2.
                        the time required to send packet 1 is 1 second.
                        the total elapsed time is now:

                            t = (totalBitsSent / restriction) + 1 = (6000/5000) + 1 = 1.2 + 1 = 2.2 seconds

                        the maximum allowable bits at time t = 2.2 are:

                            max bits = restriction * 2.2 = 5000 * 2.2 = 11000 bits

                        sending packet 1 (2000 bits) is within the limit:

                            totalBitsSent = 6000 + 2000 = 8000 <= 11000 
                            
     ----------------------------------------------------------------------------------------------------                        
                            
                    send packet 3 (size = 2000 bits, time = 1 second):
                        totalBitsSent = 8000 after packet 1.
                        the time required to send packet 3 is 1 second.
                        the total elapsed time is now:

                            t = (totalBitsSent / restriction) + 1 = (8000/5000) + 1 = 1.6 + 1 = 2.6 seconds

                        the maximum allowable bits at time t = 2.6 are:

                            max bits = restriction * 2.6 = 5000 * 2.6 = 13000 bits

                        sending packet 3 (2000 bits) is within the limit:

                            totalBitsSent = 8000 + 2000 = 10000 <= 13000 */
}
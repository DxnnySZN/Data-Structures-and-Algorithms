#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Packet {
    int size;
    int time;
};

bool compare(Packet a, Packet b) {
    return (a.size * b.time) > (b.size * a.time);
}

bool existsValidPlanning(const vector<Packet>& packets, int restriction) {
    // (size * time)
    sort(packets.begin(), packets.end(), compare);

    int totalBitsSent;

    for (const Packet& packet : packets) {
        // check if sending the current packet would exceed the bandwidth constraint
        if (totalBitsSent + packet.size > restriction * (packet.time + totalBitsSent / restriction)) {
            return false;
        }

        // update the total bits sent
        totalBitsSent += packet.size;
    }

    return true; // all packets were sent without violating the bandwidth constraint
}

int main() {
    vector<Packet> packets = { {2000, 1}, {6000, 2}, {2000, 1}} ;
    int restriction = 5000;

    if (existsValidPlanning(packets, r)) {
        cout << "a valid planning exists";
    }
    else {
        cout << "no valid planning exists";
    }
    cout << endl;
}
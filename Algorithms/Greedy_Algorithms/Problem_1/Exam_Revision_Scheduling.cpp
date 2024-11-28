/* a greedy algorithm is an approach to solving problems by making the locally optimal choice at each step 
   with the hope that these local choices lead to a globally optimal solution. 
   
   in the given code:
        the problem of minimizing waiting time is solved using a greedy algorithm by sorting students by 
        revision time and always processing the student with the shortest revision time next.

        this ensures that the waiting time for all subsequent students is minimized.
        
   greedy algorithms are efficient and straightforward but do not guarantee the best solution for all problems
   unless the problem meets specific conditions. */ 

#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

// structure to represent each student with an index and revision time
struct Student {
    int index; // student's identifier (1-based index)
    int revision_time; // time needed for the student's revision
};

// comparison function for sorting students by revision time in ascending order
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.revision_time < s2.revision_time; // return true if s1's revision time is less than s2's
}

// determines the optimal order of revision to minimize total waiting time
vector<int> minimizeWaitingTime(vector<Student>& students, int& total_waiting_time) {
    // sort students in increasing order of revision time
    sort(students.begin(), students.end(), compareStudents);

    total_waiting_time = 0;
    vector<int> revision_order; // stores the order of students for revision

    int cumulative_revision_time = 0; // tracks the cumulative revision time as we process students

    // iterates over each student in the sorted order
    for (const Student& student : students) {
        total_waiting_time += cumulative_revision_time; // adds the current cumulative revision time to the total waiting time
        revision_order.push_back(student.index); // adds the student's index to the revision order
        cumulative_revision_time += student.revision_time; // updates the cumulative revision time to include the current student's revision time
    }

    return revision_order;
}

int main() {
    int numStudents;
    cin >> numStudents;

    vector<Student> students(numStudents); // vector to store the students

    // inputs each student's revision time
    for (int i = 0; i < numStudents; ++i) {
        students[i].index = i + 1; // assigns a 1-based index to the student
        cin >> students[i].revision_time;
    }

    int total_waiting_time;

    // calculates the optimal revision order and total waiting time
    vector<int> solution = minimizeWaitingTime(students, total_waiting_time);
    
    cout << "optimal order to minimize waiting time:" << endl;
    for (int i : solution) {
        cout << "review student " << i << "'s exam" << endl;
    }
    cout << "total waiting time: " << total_waiting_time << " minutes " << endl;

    return 0;

    /* Test_Case: *num of students* 5
                  *revision time for student 1* 20
                  *revision time for student 2* 15
                  *revision time for student 3* 30
                  *revision time for student 4* 10
                  *revision time for student 5* 25
    
       Output: optimal order to minimize waiting time:
               review student 4's exam
               review student 2's exam
               review student 1's exam
               review student 5's exam
               review student 3's exam
               total waiting time: 150 minutes
               
       Explanation: students are sorted by revision times: {10, 15, 20, 25, 30}.
                    the cumulative waiting time is calculated step-by-step:
                        Student 4 (10): Wait = 0 (cumulative = 10).
                        Student 2 (15): Wait = 10 (cumulative = 25).
                        Student 1 (20): Wait = 25 (cumulative = 45).
                        Student 5 (25): Wait = 45 (cumulative = 70).
                        Student 3 (30): Wait = 70 (cumulative = 100).
                        total waiting time = 0 + 10 + 25 + 45 + 70 = 150. */
}
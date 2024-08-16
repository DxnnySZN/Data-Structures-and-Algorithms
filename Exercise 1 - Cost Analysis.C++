// fragment 1
int s = 0;
// this loop is executed a total of n times
for(int i = 0; i < n; ++i){
    ++s; /* cost = O(1) & Ω(1) => θ(1) because the time spent is at most & at least one unit time
    O(1) represents maximum time spent & Ω(1) represents minimum time spent */
}
// total cost for this fragment is n * θ(1) => θ(n) (calculate cost of piece of code inside the for loop and then see how many times this loop is running)

// fragment 2
int s = 0;
for (int i = 0; i < n; i += 2){
    ++s; // cost = O(1) & Ω(1) => θ(1)
}
/* if n = 10, i = 0, 2, 4, 6, 8 => runs 5 times
if n = 20, i = 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 => runs 10 times
this means this loop is executed a total of n/2 times
TOTAL COST: n/2 * θ(1) => θ(n/2) => θ(n) */
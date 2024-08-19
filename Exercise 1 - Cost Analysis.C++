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
TOTAL COST: n/2 * θ(1) => θ(n/2) => θ(n)

O/Ω/θ(n multiplied by a constant, divided by a constant, or added by a constant) => O/Ω/θ(n itself) */

// fragment 3
int s = 0;
for(int i = 0; i < n; ++i){ // loop is done n times
    ++s; // θ(1)
}
for(int j = 0; j < n; ++j){ // loop is done n times
    ++s; // θ(1)
}
// TOTAL COST: n * θ(1) + n * θ(1) => θ(n) + θ(n) = θ(2n) => θ(n)

// fragment 4
int s = 0;
for(int i = 0; i < n; ++i){ // loop is done n times
    for(int j = 0; j < n; ++j){ // loop is done n times
        ++s; // θ(1)
    }
    // TOTAL COST INNER FOR LOOP: n * θ(1) => θ(n)
}       /* outer for loop runtime ↓
TOTAL COST WHOLE FRAGMENT: θ(n) * n = θ(n^2) * no longer a linear cost but a quadratic cost instead * */

// fragment 5
int s = 0;
for(int i = 0; i < n; ++i){
    for(int j = 0; j < i; ++j){
        ++s;
    }
}
// iteration 1: i = 0 => no cost
// iteration 2: i = 1 => 1 time
// iteration 3: i = 2 => 2 times
// iteration 4: i = 3 => 3 times
// iteration 5: i = 4 => 4 times
// last iteration: i = (n - 1) => (n - 1) times 

/* TOTAL COST: 1 + 2 + 3 + 4 + 5 + ... + (n - 1) = (n(n - 1)) / 2
θ((n(n - 1)) / 2) => θ(n^2 - n) / 2) => approximate to θ(n^2) because n^2 is the biggest weight in the equation */

// fragment 6 (total opposite of fragment 5)
int s = 0;
for(int i = 0; i < n; ++i){
    for(int j = i; j < n; ++j){
        ++s;
    }
}
// iteration 1: i = 0 => (n - 1) times 
// iteration 2: i = 1 => (n - 2) times 
// iteration 3: i = 2 => (n - 3) times 
// previous last: i = (n - 2) => 1 time
// last: i = (n - 1) => (n - 1) times 

// TOTAL COST: (n - 1) + (n - 2) + (n - 3) + ... + 1 = (n(n - 1)) / 2 => θ(n^2)
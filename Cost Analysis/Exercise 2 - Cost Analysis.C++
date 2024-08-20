/* loop is done n - 1 times
property of O/Ω/θ notation reminder: k * θ(1) => θ(k) */
int mystery(int n){
    int f = 1;
    for(int i = 2; i <= n; ++i){
        f *= i; // θ(1)
    }
    return f;
}
// TOTAL COST: // θ(n - 1) => θ(n)

/* this function returns an integer value that is dependent on the parameter int n

examples
if n = 5, iteration 1: i = 2 | f = 1 * 2 => 2
iteration 2: i = 3 | f = 2 * 3 => 6 
iteration 3: i = 4 | f = 6 * 4 => 24
iteration 4: i = 5 | f = 24 * 5 => 120
120 is 5!

if n = 4, f will equal 4!
if n = 3, f will equal 3!
if n = 2, f will equal 2! 

to generalize this, this function given int n will return n! */
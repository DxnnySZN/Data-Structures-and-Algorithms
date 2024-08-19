int mystery(int n){
    int f = 1;
    for(int i = 2; i <= n; ++i){
        f *= i;
    }
    return f;
}
/* this function returns an integer value that is dependent on the parameter int n
if n = 5, iteration 1: i = 2 | f = 1 * 2 => 2
iteration 2: i = 3 | f = 2 * 3 => 6 
iteration 3: i = 4 | f = 6 * 4 => 24
iteration 4: i = 5 | f = 24 * 5 => 120 */
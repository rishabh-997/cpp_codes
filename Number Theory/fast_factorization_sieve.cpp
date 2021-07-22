/*
*	Fast factorization technique using sieve
*	just store arr[n] and make n = n / arr[n]
* 	traverse till n!=1
*/

vi arr;

void fast_factorization(int n) {
    arr.resize(n);
    arr.assign(arr.size(), 0);
    arr[1] = 1;
    for (int i = 2; i < n; i++)
        arr[i] = i;
    for (int i = 4; i < n; i += 2)
        arr[i] = 2;

    for (int i = 3; i * i < n; i++) {
        if (arr[i] == i) {
            for (int j = i * i; j < n; j += i) {
                if (arr[j] == j)
                    arr[j] = i;
            }
        }
    }
}

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int result = 1;
    while( n > 0 ){
        if( n & 1){
            // for odd number of exponential
            result = (1LL * result * (x) % m ) % m;
        }
        // for both Even and odd
        x = (1LL * (x) % m * (x) % m ) % m;
        n = n >> 1;
    }
    return result;
}

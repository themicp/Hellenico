#include <cstdio>
#include <cstdlib>

using namespace std;

inline long long int GCD( long long int a, long long int b ) {
       long long int temp;
    if ( b == 0 ) {
       return a;
    }
     while ( b ) {
            temp = b;
            b = a%b;
            a = temp;
     }
     return a;
}
inline long long int LCM( long long int a, long long int b ) {
    return ( a * b )/GCD( a, b );
}

int main() {
    FILE *in = fopen( "prevdiv.in", "r" );
    FILE *out = fopen( "prevdiv.out", "w" );
    long long int max = 0, lcm;
    int i, N;
    fscanf( in, "%i", &N );
    long long int a;
    fscanf( in, "%lli", &a );        
    lcm = a;
    for ( i = 0; i < N - 1; ++i ) {
        if ( ( lcm == a || a%lcm == 0 ) && a > max ) {
            max = a;
        }
        lcm = LCM( lcm, a );
        if ( lcm > 2000000000 ) {
           break;
        }
        fscanf( in, "%lli", &a );
    }
    fprintf( out, "%lli\n", max );
    fclose( in );
    fclose( out );
    return 0;
}

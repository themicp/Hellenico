#include <cstdio>
#include <cstdlib>

using namespace std;

bool isPrime ( int a ) {
    int i;
    bool prime = true;

    for ( i = 2; i < a; ++i ) {
        if ( a % i == 0 && i != a ) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {
    FILE *in = fopen( "goldbach.in", "r" );
    FILE *out = fopen( "goldbach.out", "w" );

    int n;
    int a = 2, b = 2;
    int i;
    bool done = false;

    fscanf( in, "%i", &n );
    b = n - 1;

    while ( !done ) {
        if ( isPrime( a ) ) {
            b = n - a;
            if ( isPrime( b ) ) {
                if ( a + b == n && isPrime( a ) && isPrime( b ) ) {
                    done = true;
                    break;
                }
            }
        }
        ++a;
    }

    fprintf( out, "%i %i\n", a, b );
    fclose( in );
    fclose( out );
    return 0;
}

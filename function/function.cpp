#include <cstdio>
#include <cstdlib>

using namespace std;

void Sieve( bool *A, int N, int start ) {
    int i, o;

    if ( start == 1 ) {
        start = 2;
    }

    for ( i = 2; i*i < N; ++i ) {
        o = 2;
        while ( o * i <= N ) {
            A[ o * i ] = false;
            ++o;
        }
    }
}

FILE *in = fopen( "function.in", "r" ), *out = fopen( "function.out", "w" );
int N, M, K, t, i, count = 0;
bool *primes;

int main() {
    fscanf( in, "%i %i", &N, &M );
    if ( N > M ) {
        t = M;
        M = N;
        N = t;
    }

    primes = ( bool* )malloc( ( M + 1 ) * sizeof( bool ) ); 

    for ( i = 3; i <= M; ++i ) {
        primes[ i ] = true;
    }

    Sieve( primes, M, N );

    for ( i = N + 1; i < M; ++i ) {
        if ( primes[ i ] ) {
            if ( count == 0 ) {
                fprintf( out, "%i", i );
                ++count;
            }
            else {
                fprintf( out, " %i", i );
            }
        }
    }
    if ( count > 0 ) {
        fprintf( out, "\n" );
    }
    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int N, D, *A, k, j, max;
FILE *in = fopen( "piano.in", "r" ), *out = fopen( "piano.out", "w" );

int main() {
    fscanf( in, "%i %i\n", &N, &D );

    A = ( int* )malloc( N * sizeof( int ) );

    for ( k = 0; k < N; ++k ) {
        fscanf( in, "%i", &A[ k ] );
    }

    for ( k = 0; k < N; ++k ) {
        for ( j = 1; j <= D; ++j ) {
            if ( k + j >= N ) {
                continue;
            }
            if ( A[ k ] > A[ j + k ] && A[ k ] - A[ k + j ] > max ) {
                max = A[ k ] - A[ k + j ];
            }
        }
    }

    fprintf( out, "%i\n", max );

    return 0;
}

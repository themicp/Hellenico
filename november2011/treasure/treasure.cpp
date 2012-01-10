#include <cstdio>
#include <cstdlib>

using namespace std;

FILE *in = fopen( "treasure.in", "r" ), *out = fopen( "treasure.out", "w" );
int N, Q, k, j, i, *A, cmd, dat1, dat2, response;

int main() {
    fscanf( in, "%i %i\n", &N, &Q );

    A = ( int* )malloc( N * sizeof( int ) );

    for ( k = 0; k < N; ++k ) {
        fscanf( in, "%i", &A[ k ] );
    }

    for ( k = 0; k < Q; ++ k ) {
        fscanf( in, "%i %i %i", &cmd, &dat1, &dat2 );
        --dat1;
        if ( cmd == 0 ) {
            A[ dat1 ] = dat2;
        }
        if ( cmd == 1 ) {
            response = 0;
            i = 1;
            for ( j = dat1; j < dat2; ++j ) {
                response += i * A[ j ]; 
                ++i;
            }
            fprintf( out, "%i\n", response % 1000000007 );
        }
    }

    return 0;
}

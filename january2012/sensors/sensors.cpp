#include <cstdio>

using namespace std;

FILE *in = fopen( "sensors.in", "r" ), *out = fopen( "sensors.out", "w" );
int N, C, R, i, j, sensors[ 51 ][ 51 ], x, y;

int main() {
    fscanf( in, "%i %i %i", &N, &R, &C );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i", &y, &x );
        sensors[ y ][ x ] += 1;
        for ( j = 0; j <= 50; ++j ) {
            if ( j != x ) {
                sensors[ y ][ j ] += 1;
            }
            if ( j != y ) {
                sensors[ j ][ x ] += 1;
            }
        }
    }

    fprintf( out,"%i\n", sensors[ R ][ C ] );

    return 0;
}

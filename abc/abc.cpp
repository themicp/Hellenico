#include <cstdio>

using namespace std;

int main() {
    FILE * in;
    FILE * out;
    int i, ints, a[ 3 ];
    char order[ 5 ];
    int max = 0, mid = 0, low = 0;
    int b[ 3 ];
    
    out = fopen( "abc.out", "w" );
    in = fopen( "abc.in", "r" );
    
    for ( i = 0; i < 3; ++i ) {
        fscanf( in, "%i", &ints );
        a[ i ] = ints;
    }
    max = a[ 2 ];
    for ( i = 0; i < 3; ++i ) {
        fscanf( in, "%s", order );
    }
    for ( i = 0; i < 3; ++i ) {
        if ( max < a[ i ] ) {
            max = a[ i ];
        }
    }
    for ( i = 0; i < 3; ++i ) {
        if ( a[ i ] > mid && a[ i ] < max ) {
            mid = a[ i ];
        }
    }
    for ( i = 0; i < 3; ++i ) {
        if ( a[ i ] < mid ) {
            low = a[ i ];
        }
    }
    for ( i = 0; i < 3; ++i ) {
        if ( order[ i ] == 'A' ) {
            b[ i ] = low;
        }
        if ( order[ i ] == 'B' ) {
            b[ i ] = mid;
        }
        if ( order[ i ] == 'C' ) {
            b[ i ] = max;
        }
    }
    for ( i = 0; i < 3; ++i ) {
        if ( i == 2 ) {
            fprintf( out, "%i\n", b[ i ] );
        }
        else {
            fprintf( out, "%i ", b[ i ] );
        }
    }
    return 0;
}

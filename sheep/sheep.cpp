#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int i, o;
    int a[ 2 ];
    FILE * in;
    FILE * out;
    char b[ 15 ];
    int count[ 10 ];
    
    for ( i = 0; i < 10; ++i ) {
        count[ i ] = 0;
    }

    in = fopen( "sheep.in", "r" );
    out = fopen( "sheep.out", "w" );

    fscanf( in, "%i", &a[ 0 ] );
    fscanf( in, "%i", &a[ 1 ] );

    for ( i = a[ 0 ]; i < a[ 1 ] + 1; ++i ) {
        sprintf( b, "%i", i );
        for ( o = 0; b[ o ] != '\0'; ++o ) {
            count[ b[ o ] - '0' ] += 1; 
        }
    }
    for ( i = 0; i < 10; ++i ) {
        if ( i == 9 ) {
            fprintf( out, "%i\n", count[ i ] );
        }
        else {
            fprintf( out, "%i ", count[ i ] );
        }
    }
    return 0;
}

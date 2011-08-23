#include <cstdio>
#include <cstdlib>

using namespace std;

int cmp( const void* a, const void* b ) {
    int one = *( int* )a;
    int two = *( int* )b;

    if ( one > two ) {
        return 1;
    }
    else if ( two < one ) {
        return -1;
    }
    return 0;
}

int main() {
    FILE* in = fopen( "elevator.in", "r" );
    FILE* out = fopen( "elevator.out", "w" );

    int i;
    int k = 0, j;
    int max = 0;
    int count = 0;
    int n;
    int* w;
    bool flag = false;

    fscanf( in, "%i", &n );

    w = ( int* )malloc( n * sizeof( int ) );

    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%i", &w[ i ] );
    }

    qsort( w, n, sizeof( int ), cmp );

    for ( i = 0; i < n; ++i ) {
        printf( "%i\n", w[ i ] );
    }

    j = n - 1;

    while ( j > k ) {
        if ( n % 2 == 1 && !flag) {
            printf( "max set to %i\n", w[ j ] );  
            max += w[ j ];
            --j;
            flag = true;
        }
        else {
            if ( w[ k ] + w[ j ] > max ) {
                printf( "max changed from %i to %i\n", max, w[ k ] + w[ j ] );  
                max = w[ k ] + w[ j ];
            }
            ++k;
            --j;
        }
        ++count;
    }

    fprintf( out, "%i %i\n", count, max );

    return 0;
}

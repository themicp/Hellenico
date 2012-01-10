#include <cstdio>

using namespace std;

int countChange( int N, int *cash ) {
    int k = 5, change = 0;
    
    while( N < cash[ k ] ) {
        --k;
    }

    change = N / cash[ k ];

    N -= change * cash[ k ];

    if ( N > 0 ) {
        return change + countChange( N, cash );
    }

    return change;
}

FILE *in = fopen( "resta.in", "r" ), *out = fopen( "resta.out", "w" );
int N, cash[ 6 ] = { 1, 2, 5, 10, 50, 100 }, k, change;

int main() {
    fscanf( in, "%i\n", &N );

    change = countChange( N, cash );

    fprintf( out, "%i\n", change );

    return 0;
}

#include <cstdio>

using namespace std;

float find_profit( int* array, int elems ) {
    int k, o = 0;
    int buy;
    int sell;
    float profit = 1.0;
    for ( int i = 0; i < elems; ++i ) {
        for ( k = i; k < elems; ++k ) {
            if ( ( (double)array[ k ] / array[ i ] ) > profit ) {
                profit = (double)array[ k ] / array[ i ];
            }
        }
    }
    return profit;
}

int main() {
    int n, x, l;
    FILE * out;
    FILE * in;

    in = fopen( "profit.in", "r" );
    fscanf( in, "%i", &n );

    int a[ n ];

    for ( l = 0; l < n; ++l ) {
        fscanf( in, "%i", &x );
        a[ l ] = x;
    }

    fclose( in );
    out = fopen( "profit.out", "w" );

    fprintf( out, "%.3f\n", find_profit( a, n ) );

    fclose( out );
    
    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    FILE *in = fopen( "sort3.in", "r" );
    FILE *out = fopen( "sort3.out", "w" );
    int i;
    int N;
    int min, max;
    int p, q;
    int *a;
    int temp;
    int diffs = 0;
    
    fscanf( in, "%i", &N );
    
    a = ( int* )malloc( N * sizeof( int ) );
    
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &a[ i ] );
    }
    
    p = 0;
    q = N - 1;
    min = p;
    max = q;

    while ( p < N && q > -1 ) {
          if ( a[ p ] < a[ min ] ) {
             temp = a[ min ];
             a[ min ] = a[ p ];
             a[ p ] = temp;
             min = p;
             ++diffs;
          }
          if ( a[ q ] > a[ max ] ) {
             temp = a[ max ];
             a[ max ] = a[ q ];
             a[ q ] = temp;
             max = q;
             ++diffs;
          }
          ++p;
          --q;
          if ( p > q ) {
             temp = min;
             min = max;
             max = temp;   
          }
    }
    
    fprintf( out, "%i\n", diffs );
    
    return 0;
}


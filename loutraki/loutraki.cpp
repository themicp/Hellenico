/*
USER: pdp24u10
LANG: C++
TASK: loutraki
*/
#include <cstdio>  
  
int N, c[ 1000002 ][ 2 ], i, j, k, s;  
FILE *in = fopen( "loutraki.in", "r" ), *out = fopen( "loutraki.out", "w" );  
  
int main() {  
    fscanf( in, "%i", &N );  
      
    for ( i = 0; i < N; ++i ) {  
        fscanf( in, "%i %i", &c[ i ][ 0 ], &c[ i ][ 1 ] );  
    }  
  
    for ( i = 0; i < N; ++i ) {  
        k = 0;  
        for ( j = 0; j < N; ++j ) {  
            if ( j != i ) {  
                if ( c[ i ][ 0 ] == c[ j ][ 0 ] ) {  
                    if ( c[ j ][ 1 ] < c[ i ][ 1 ] ) {  
                        ++k;  
                    }  
                }  
                if ( c[ i ][ 1 ] == c[ j ][ 1 ] ) {  
                    if ( c[ j ][ 0 ] < c[ i ][ 0 ] ) {  
                        ++k;  
                    }  
                }  
            }  
        }  
        if ( k == 0 ) {  
            ++s;  
        }  
    }  
    fprintf( out, "%i\n", s );  
  
    return 0;  
}  

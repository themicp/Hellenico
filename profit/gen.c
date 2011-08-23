#include <stdlib.h>
#include <stdio.h>

#define N 1000000
#define X 1000

int main() {
    FILE* file = fopen( "profit.in", "w" );
        fprintf( file, "%d\n", N );
        
        int i;
        for ( i = 0; i < N; ++i ) {
            int num = rand() % X + 1;
            fprintf( file, "%d ", num );
        }

        fputc( '\n', file );
    fclose( file );

    return 0;
}

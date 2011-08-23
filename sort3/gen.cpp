#include <cstdio>

int main() {
    int i;
    int n = 999;
    int key = 1;
    int count = 0;
    FILE *out = fopen( "sort3.in", "w" );

    fprintf( out, "%i\n", n );

    for ( i = 0; i < n; ++i ) {
        if ( count == n/3 ) {
            ++key;
            count = 0;
        }
        fprintf( out, "%i\n", key );
        ++count;
    }
}

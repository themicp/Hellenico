#include <cstdio>
#include <cstdlib>

using namespace std;

struct File {
    float time;
    int speed;
};

int cmp ( const void* a, const void* b ) {
    return ( ( *( File* )a ) .time - ( *( File* )b ).time );
    return 0;
}

int main() {
    FILE* in = fopen( "downloads.in", "r" );
    FILE* out = fopen( "downloads.out", "w" );

    struct File *files;
    int i;
    int n;
    float res = 0;

    fscanf( in, "%i", &n );

    files = ( File* )malloc( n * sizeof( File ) );

    for ( i = 0; i < n; ++i ) {
        fscanf( in,  "%i %f", &files[ i ].speed, & files[ i ].time );
    }

    qsort( files, n, sizeof( File ), cmp );
   
    for ( i = 0; i < n; ++i ) {
        res += files[ i ].time;
        if ( i < n - 1 ) {
            files[ i + 1 ].time -= res;
            files[ i + 1 ].time *= ( float )files[ i + 1 ].speed / ( files[ i ].speed + files[ i + 1 ].speed );
            files[ i + 1 ].speed += files[ i ].speed;
        }
    }

    fprintf( out, "%.0f\n", res );

    free( files );
    return 0;
}

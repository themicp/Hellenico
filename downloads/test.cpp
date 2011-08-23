#include <cstdio>
#include <cstdlib>

using namespace std;

struct Test { 
    int a;
    int cmp;
};

int cmp ( const void* a, const void* b ) {
    struct Test one = *( struct Test* )a;
    struct Test two = *( struct Test* )b;

    return ( one.cmp - two.cmp );
    return 0;
}

int main() {
    int i;
    struct Test array[ 2 ];
    array[ 1 ].a = 5;
    array[ 1 ].cmp = 4;
    array[ 0 ].a = 10;
    array[ 0 ].cmp = 5;

    for ( i = 0; i < 2; ++i ) {
        printf( "a %i cmp %i\n", array[ i ].a, array[ i ].cmp );
    }

    printf( "QSORT\n" );
    qsort( array, 2, sizeof( struct Test ), cmp );

    for ( i = 0; i < 2; ++i ) {
        printf( "a %i cmp %i\n", array[ i ].a, array[ i ].cmp );
    }
    return 0;
}

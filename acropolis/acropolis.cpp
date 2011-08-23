#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int cmp ( const void* a, const void* b ) {
    int one = *( int* )a;
    int two = *( int* )b;

    if ( one > two ) {
        return 1;
    }
    else if ( two > one ) {
        return -1;
    }
    return 0;
}

int main() {
    FILE *in = fopen( "acropolis.in", "r" );
    FILE *out = fopen( "acropolis.out", "w" );
    int i;
    int* a;
    int n;
    int top;
    int temp, prev;
    stack< int > pos;

    fscanf( in, "%i", &n );

    a = ( int* )malloc( n * sizeof( int ) );

    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%i", &a[ i ] );
    }
    for ( i = 0; i < n; ++i ) {
        if ( a[ i ] == 1 ) {
            pos.push( i );
        }
    }
    qsort( a, n, sizeof( int ), cmp );
    while( !pos.empty() ) {
        top = pos.top();
        temp = a[ top ];
        for ( i = top; i > 0; --i ) {
            prev = a[ i - 1 ];
            a[ i - 1 ] = temp;
            temp = prev;
        }
        a[ top ] = 1;
        pos.pop();
    }

    for ( i = 0; i < n; ++i ) {
        fprintf( out, "%i\n", a[ i ] );
    }

    return 0;
}

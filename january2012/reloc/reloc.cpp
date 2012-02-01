#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int cmp (const void * a, const void * b) {
      return ( *(int*)a - *(int*)b );
}

int min( int a, int b ) {
    if ( abs( a ) <= abs( b ) ) {
        return a;
    }
    return b;
}

FILE *in = fopen( "reloc.in", "r" ), *out = fopen( "reloc.out", "w" );
int i, j, N, K, it, count;
int* A;
priority_queue< int > friends;

int main() {
    fscanf( in, "%i %i", &N, &K );

    A = ( int* )malloc( N * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
    }

    qsort( A, N, sizeof( int ), cmp );

    it = N - 1;
    while ( A[ it ] >= 0 && it >= 0 ) {
        --it;
    }
    ++it;

    i = it - 1;
    while ( count < K ) {
        if ( i == -1 && it != -1 ) {
            friends.push( -A[ it ] );
        }
        if ( i != -1 && it == -1 ) {
            friends.push( -A[ i ] );
        }
        if ( i != -1 && it != -1 ) {
            friends.push( -min( A[ i ], A[ it ] ) );
        }
        ++count;
        if ( i == 0 ) {
            i = -1;
        }
        if ( it == 0 ) {
            it = -1;
        }
        if ( min( A[ i ], A[ it ] ) == A[ i ] && i >= 0 ) {
            --i;
        }
        else if ( min( A[ i ], A[ it ] ) == A[ it ] && A[ it ] < N ) {
            ++it;
        }
    }

    while( !friends.empty() ) {
        fprintf( out, "%i\n", -friends.top() );
        friends.pop();
    }

    return 0;
}

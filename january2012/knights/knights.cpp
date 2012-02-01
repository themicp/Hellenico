#include <cstdio>

using namespace std;

bool BF( int *A, int N, int i ) {
    if ( A[ i ] == 3 ) {
        A[ i ] = 0;
        if ( i == 0 ) {
            return true;
        }
        return BF( A, N, i - 1 );
    }
    else {
        ++A[ i ];
        return false;
    }
}

bool move( int A[ 4 ][ 2 ], int N, int tactic, int i, int j ) {
    A[ i ][ j ] = 1;
    switch( tactic ) {
        case 1: //up up right
            if ( i - 2 < 0 ) {
                return false;
            }
            if ( j + 1 >= N ) {
                return false;
            }
            if ( A[ i - 1 ][ j ] != 1 ) {
                A[ i - 1 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j ] != 1 ) {
                A[ i - 2 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j + 1 ] != 1 ) {
                A[ i - 2 ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 2: // up up left
            if ( i - 2 < 0 ) {
                return false;
            }
            if ( j - 1 < 0 ) {
                return false;
            }
            if ( A[ i - 1 ][ j ] != 1 ) {
                A[ i - 1 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j ] != 1 ) {
                A[ i - 2 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j - 1 ] != 1 ) {
                A[ i - 2 ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 3: // up right right
            if ( i - 1 < 0 ) {
                return false;
            }
            if ( j + 2 >= N ) {
                return false;
            }
            if ( A[ i - 1 ][ j ] != 1 ) {
                A[ i - 1 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j + 1 ] != 1 ) {
                A[ i - 1 ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j + 2 ] != 1 ) {
                A[ i - 1 ][ j + 2 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 4: // up left left
            if ( i - 1 < 0 ) {
                return false;
            }
            if ( j - 2 < 0 ) {
                return false;
            }
            if ( A[ i - 1 ][ j ] != 1 ) {
                A[ i - 1 ][ j ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j - 1 ] != 1 ) {
                A[ i - 1 ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j - 2 ] != 1 ) {
                A[ i - 1 ][ j - 2 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 5: // left up up
            if ( i - 2 < 0 ) {
                return false;
            }
            if ( j - 1 < 0 ) {
                return false;
            }
            if ( A[ i ][ j - 1 ] != 1 ) {
                A[ i ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j - 1 ] != 1 ) {
                A[ i - 1 ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j - 1 ] != 1 ) {
                A[ i - 2 ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 6: // right up up
            if ( i - 2 < 0 ) {
                return false;
            }
            if ( j + 1 >= N ) {
                return false;
            }
            if ( A[ i ][ j + 1 ] != 1 ) {
                A[ i ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j + 1 ] != 1 ) {
                A[ i - 1 ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 2 ][ j + 1 ] != 1 ) {
                A[ i - 2 ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 7: // right right up
            if ( i - 1 < 0 ) {
                return false;
            }
            if ( j + 2 >= N ) {
                return false;
            }
            if ( A[ i ][ j + 1 ] != 1 ) {
                A[ i ][ j + 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i ][ j + 2 ] != 1 ) {
                A[ i ][ j + 2 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j + 2 ] != 1 ) {
                A[ i - 1 ][ j + 2 ] = 1;
            }
            else {
                return false;
            }
            break;
        case 8: // left left up
            if ( i - 1 < 0 ) {
                return false;
            }
            if ( j - 2 < 0 ) {
                return false;
            }
            if ( A[ i ][ j - 1 ] != 1 ) {
                A[ i ][ j - 1 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i ][ j - 2 ] != 1 ) {
                A[ i ][ j - 2 ] = 1;
            }
            else {
                return false;
            }
            if ( A[ i - 1 ][ j - 2 ] != 1 ) {
                A[ i - 1 ][ j - 2 ] = 1;
            }
            else {
                return false;
            }
            break;
    }
    return true;
}

int A[ 2 ], i, j, board[ 4 ][ 2 ];

int main() {
    while( !BF( A, 2, 1 ) ) {
        for ( i = 0; i < 2; ++i ) {
            printf( "%i ", A[ i ] );
        }
        printf( "\n" );
    }

        printf( "\n BOARD\n" );
    if ( !move( board, 2, 5, 3, 1 ) ) {
        printf( "Error\n" );
    }
    else {
        printf( "Done\n" );
    }
    for ( i = 0; i < 4; ++i ) {
        for ( j = 0; j < 2; ++j ) {
            printf( "%i ", board[ i ][ j ] );
        }
        printf( "\n" );
    }
    return 0;
}

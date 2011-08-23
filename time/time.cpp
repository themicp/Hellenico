#include <cstdio>

using namespace std;

void timer ( int a[ 3 ] ) {
    int mina = 0, hoursa = 0;
    int res[ 3 ];
    int hours = a[ 0 ], mins = a[ 1 ], secs = a[ 2 ];
    char sec[ 3 ];
    char min[ 3 ];
    char hour[ 3 ];
    FILE * out;
    out = fopen( "time.out", "w" );
    if ( secs <= 29 ) {
        secs *= 2;
    }
    else {
        secs = secs * 2 - 60;
        mina = 1;
    }
    if ( mins <= 29 ) {
        mins *= 2; 
        mins += mina;
    }
    else {
        mins = mins * 2 - 60 + mina;
        hoursa = 1;
    }
    hours *= 2;
    hours += hoursa;
    if ( hours < 2 ) {
        hour[ 0 ] = '0';
        hour[ 1 ] = '0' + hours;
        hour[ 2 ] = '\0';
        fprintf( out, "%s:", hour );
    }
    else {
        fprintf( out, "%i:", hours );
    }
    if ( mins <= 10 ) {
        min[ 0 ] = '0';
        min[ 1 ] = '0' + mins;
        min[ 2 ] = '\0';
        fprintf( out, "%s:", min );
    }
    else {
        fprintf( out, "%i:", mins );
    }
    if ( secs < 10 ) {
        sec[ 0 ] = '0';
        sec[ 1 ] = '0' + secs;
        sec[ 2 ] = '\0';
        fprintf( out, "%s\n", sec );
    }
    else {
        fprintf( out, "%i\n", secs );
    }
}

int main() {
    FILE * in;
    int b[ 3 ], i, x;

    in = fopen( "time.in", "r" );

    for ( i = 0; i < 3; ++i ) {
        fscanf( in, "%i", &x );
        fscanf( in, ":" );
        b[ i ] = x;
    }
    timer( b );

    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

struct timeTable {
    float start;
    float end;
};

void cross( float &currentTime, float &x, float &y, timeTable *times, int key, int N ) {
    if ( key >= N ) {
        return;
    }
    if ( currentTime >= times[ key ].start ) {
        if ( times[ key ].end - currentTime >= 1 ) {
            currentTime += 1;
            ++x;
            cross( currentTime, x, y, times, key + 1, N );
        }
        else {
            return;
        }
    }
    else if ( currentTime < times[ key ].start ) {
        y += times[ key ].start - currentTime;
        currentTime += times[ key ].start - currentTime;
        if ( times[ key ].end - currentTime >= 1 ) {
            currentTime += 1;
            ++x;
            cross( currentTime, x, y, times, key + 1, N );
        }
        else {
            return;
        }
    }
}

FILE *in = fopen( "robbery.in", "r" ), *out = fopen( "robbery.out", "w" );
int N, L, i;
float totalTime, x, y;
timeTable *times;

int main() {
    fscanf( in, "%i %i", &N, &L );

    times = ( timeTable* )malloc( N * sizeof( timeTable ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%f %f", &times[ i ].start, &times[ i ].end );
    }

    cross( totalTime, x, y, times, 0, N );

    if ( N == x ) {
       totalTime += L - y;
       fprintf( out, "Y %.2f\n", totalTime );
    }
    else {
        fprintf( out, "N %.0f\n", x );
    }

    return 0;
}

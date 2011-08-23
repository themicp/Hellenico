#include "hiddenlib.h"

int n;

int main() {
    int hi, lo;
    short cmp;
    n = getN();

    while ( true ) {
        cmp = compare( lo, hi );
        if ( cmp == 1 ) {
            if ( ishidden( lo ) ) return 1;
            ++lo;
            hi = ( lo + hi ) / 2;
        }
        if ( cmp == 0 ) return ishidden( ( lo + hi )/2 );
        if ( cmp == -1 ) {
            if ( ishidden( hi ) ) return 1;
            lo = ( lo + hi ) / 2;
            --hi;
        }
    }
    return 0;
}

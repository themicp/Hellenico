#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector< string > cars;

int main() {
    FILE *in = fopen( "boat.in", "r" );
    FILE *out = fopen( "boat.out", "w" );
    int i, o;
    string str;
    char car[ 43 ];
    int N, *x, *y;
    vector< string >::iterator it;
   
    fscanf( in, "%i", &N );

    x = ( int* )malloc( N * sizeof( int ) );
    y = ( int* )malloc( N * sizeof( int ) );
    
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i", &x[ i ], &y[ i ] );
        for ( o = 0; o < x[ i ]; ++o ) {
            cars.pop_back();
        }
        for ( o = 0; o < y[ i ]; ++o ) {
            fscanf( in, "%s", car );
            cars.push_back( car );
        }
    }
    
    sort( cars.begin(), cars.end() );
    
    for ( it = cars.begin(); it < cars.end(); ++it ) {
        fprintf( out, "%s\n", ( *it ).c_str() );
    } 

    fclose( in );
    fclose( out );
    return 0;
}

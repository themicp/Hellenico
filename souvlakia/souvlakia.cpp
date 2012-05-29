/*
USER: pdp24u10
LANG: C++
TASK: souvlakia
*/
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

const int INF = 987654321;

struct Neighbor {
        int u;
        int w;
};

priority_queue< pair< int, pair< int, int > > > q;
pair< int, int > top;
int N, M, L, i, j, vill[ 3 ], u, v, t[ 50005 ], n[ 100005 ], T, W[ 100005 ], k;
int w, d[ 3 ], error, lens[ 50005 ][ 3 ];
FILE *in = fopen( "souvlakia.in", "r" ), *out = fopen( "souvlakia.out", "w" );
bool marked[ 100002 ], S[ 50005 ];
Neighbor **E;
Neighbor x;

int main() {
    fscanf( in, "%i %i", &N, &M );

    E = (Neighbor**)malloc( N * sizeof( Neighbor* ) );

    for ( i = 0; i < N; ++i ) {
        E[ i ] = (Neighbor*)malloc( N * sizeof( Neighbor ) );
        W[ i ] = INF;
    }

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        E[ u ][ n[ u ] ].u = v;
        E[ u ][ n[ u ] ].w = w;
        E[ v ][ n[ v ] ].u = u;
        E[ v ][ n[ v ] ].w = w;
        ++n[ u ];
        ++n[ v ];
    }
    fscanf( in, "%i %i %i %i", &vill[ 0 ], &vill[ 1 ], &vill[ 2 ], &L );
    --vill[ 0 ];
    --vill[ 1 ];
    --vill[ 2 ];
    d[ 0 ] = d[ 1 ] = d[ 2 ] = INF;
    for ( i = 0; i < L; ++i ) {
        fscanf( in, "%i", &t[ i ] );
        --t[ i ];
    }

    for ( k = 0; k < L; ++k ) {
        error = 0;
        for ( j = 0; j < 3; ++j ) {
            for ( i = 0; i < N; ++i ) {
                W[ i ] = INF;
                marked[ i ] = 0;
            }
            for ( i = 0; i < n[ vill[ j ] ]; ++i ) {
                q.push( make_pair( -E[ vill[ j ] ][ i ].w, make_pair( vill[ j ], E[ vill[ j ] ][ i ].u ) ) );
                W[ E[ vill[ j ] ][ i ].u ] = E[ vill[ j ] ][ i ].w;
            }
            marked[ vill[ j ] ] = 1;

            while ( !q.empty() ) {
                w = q.top().first;
                top = q.top().second;
                W[ top.second ] = min( W[ top.second ], -w );
                for ( i = 0; i < n[ top.second ]; ++i ) {
                    x = E[ top.second ][ i ];
                    if ( !marked[ x.u ] ) {
                        q.push( make_pair( -( x.w + ( -w ) ), make_pair( top.second, x.u ) ) );
                    }
                }
                marked[ top.second ] = 1;
                q.pop();
            }
            lens[ k ][ j ] = W[ t[ k ] ] == INF ? 0 : W[ t[ k ] ];
        }
        if ( k > 0 ) {
            for ( i = k - 1; i >= 0; --i ) {
                if ( lens[ k ][ 0 ] > lens[ i ][ 0 ] && 
                    lens[ k ][ 1 ] > lens[ i ][ 1 ] &&
                    lens[ k ][ 2 ] > lens[ i ][ 2 ] ) {
                        S[ k ] = 0;
                        break;
                }
                else {
                    S[ k ] = 1;
                }
            }
        }
        else {
            S[ k ] = 1;
        }
    }
    for ( i = 0; i < L; ++i ) {
        if ( S[ i ] == 1 ) {
            fprintf( out, "YES\n" );
        }
        else {
            fprintf( out, "NO\n" );
        }
    }

    return 0;
}


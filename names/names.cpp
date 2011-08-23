#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
  
using namespace std;  
  
void minChar( char name[ 21 ], char target[ 21 ] ) {  
    int len = strlen( name );  
    int i;  
    char newname[ 21 ];  
    strcpy( newname, name );  
    char last;  
    strcpy( target, name );  
    int counter = 0;  
  
    while ( counter < len ) {  
        last = newname[ len - 1 ];  
        for ( i = len - 1; i > 0; --i ) {  
            newname[ i ] = newname[ i - 1 ];   
        }  
        newname[ 0 ] = last;  
        ++counter;  
        if ( strcmp( newname, target ) < 0 ) {  
            strcpy( target, newname );  
        }  
    }  
}  
  
int main() {  
    FILE *in = fopen( "names.in", "r" );  
    FILE *out = fopen( "names.out", "w" );  
    int n;  
    int i;  
    char temp[ 21 ];  
    char min[ 21 ];  
    int key = 0;  
  
    fscanf( in, "%i\n", &n );  
  
    char names[ n ][ 21 ];  
  
    for ( i = 0; i < n; ++i ) {  
        fscanf( in, "%s\n", &names[ i ] );  
    }  
  
    minChar( names[ 0 ], min );  
  
    for ( i = 0; i < n; ++i ) {  
        minChar( names[ i ], temp );  
        if ( strcmp( temp, min ) < 0 ) {  
            strcpy( min, temp );  
            key = i;  
        }  
    }  
  
    fprintf( out, "%s\n", names[ key ] );  
  
    return 0;  
}  

#include <cstdio>

using namespace std;

struct Employee {
    int head;
    int gender;
};

int main() {
    int count, i, males = 0, females = 0;
    int temp;
    int r[ 2 ];
    r[ 0 ] = 0;
    r[ 1 ] = 0;
    char gender[ 1 ];
    FILE * in = fopen( "company.in", "r" );
    FILE * out = fopen( "company.out", "w" );
    fscanf( in, "%i", &count );
    struct Employee emps[ count ];
    for ( i = 0; i < count; ++i ) {
        fscanf( in, "%i", &emps[ i ].head );
        --emps[ i ].head;
        fscanf( in, " " );
        fscanf( in, "%c", gender );
        if ( gender[ 0 ] == 'm' ) {
            emps[ i ].gender = 0;
        }
        else {
            emps[ i ].gender = 1;
        }
    }
    for ( i = 0; i < count; ++i ) {
        temp = emps[ i ].head + 1;
        while ( temp ) {  
            --temp;
            if ( emps[ temp ].gender != emps[ i ].gender ) {  
                ++r[ emps[ i ].gender ]; 
            }  
            temp = emps[ temp ].head + 1;  
        }
    }
    fprintf( out, "%i\n", r[ 1 ] - r[ 0 ] );
    return 0;
}

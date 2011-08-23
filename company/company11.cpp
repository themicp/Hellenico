#include <cstdio>

using namespace std;

struct Employees {
    int head;
    int assocs[ 5000 ];
    int count;
    char gender[ 1 ];
};

void addAssoc ( struct Employees* emps, int head, int assoc ) {
    int temp = head;
    int count;
    while ( temp ) {
        if ( assoc + 1 != head ) {
            count = emps[ temp - 1 ].count;
            emps[ temp - 1 ].assocs[ count ] = assoc + 1;
            ++emps[ temp - 1 ].count;
            if ( temp == 0 ) {
                break;
            }
            temp = emps[ temp - 1 ].head;
        }
    }
}

int main() {
    int count, chief, i, o, head, males = 0, females = 0;
    int temp;
    FILE * in = fopen( "company.in", "r" );
    FILE * out = fopen( "company.out", "w" );
    fscanf( in, "%i", &count );
    struct Employees emps[ count ];
    for ( i = 0; i < count; ++i ) {
        emps[ i ].gender[ 1 ] = '\0';
        emps[ i ].count = 0;
    }
    for ( i = 0; i < count; ++i ) {
        fscanf( in, "%i", &emps[ i ].head );
        fscanf( in, " " );
        fscanf( in, "%c", &emps[ i ].gender[ 0 ] );
    }
    for ( i = 0; i < count; ++i ) {
        addAssoc( emps, emps[ i ].head, i );
    }
    /*
    for ( i = 0; i < count; ++i ) {
        head = emps[ i ].head;
        for ( o = 0; o < emps[ i ].count; ++o ) {
            if ( emps[ i ].gender[ 0 ] == 'm' ) {
                temp = &emps[ i ].assocs[ o ];
                if ( emps[ *temp - 1 ].gender[ 0 ] == 'f' ) {
                    males += 1;
                }
            }
            else {
                temp = &emps[ i ].assocs[ o ];
                if ( emps[ *temp - 1 ].gender[ 0 ] == 'm' ) {
                    females += 1;
                }
            }
        }
    }*/
    for ( i = 0; i < count; ++i ) {
        temp = emps[ i ].head;
        if ( emps[ i ].gender[ 0 ] == 'm' ) {
            while ( temp ) {
                if ( temp != i + 1 ) {
                    if ( emps[ temp - 1 ].gender[ 0 ] == 'f' ) {
                        females += 1;
                    }
                }
                temp = emps[ temp - 1 ].head;
            }
        }
        else {
            while ( temp ) {
                if ( temp != i + 1 ) {
                    if ( emps[ temp - 1 ].gender[ 0 ] == 'm' ) {
                        males += 1;
                    }
                }
                temp = emps[ temp - 1 ].head;
            }
       }
    }
    fprintf( out, "%i\n", males - females );
    return 0;
}

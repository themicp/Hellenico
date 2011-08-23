#include <cstdio>

using namespace std;

int main() {
    int a = 5;
    int * b;
    b = &a;
    printf( "%i", *b );
    ++*b;
    printf( "%i", *b );
    return 0;
}

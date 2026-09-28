/* ------------------------------------------------------------
   Programming Fundamentals - Lab exercise
   Task    : Geometry Area #1 - Rectangle
   Student : <student id> <full name>
   ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TXT_LEN 64

/* whole numbers are printed without decimals, others with 2 */
static void to_text( double num, char *out ) {
    if ( !isinf( num ) && num == floor( num ) )
        sprintf( out, "%lld", (long long)num );
    else
        sprintf( out, "%.2f", num );
}

int main( void ) {
    double width, height;
    double area, peri;
    char areaTxt[TXT_LEN];
    char periTxt[TXT_LEN];

    width = 0;
    height = 0;
    scanf( "%lf", &width );
    scanf( "%lf", &height );

    area = width * height;
    peri = 2 * ( width + height );

    to_text( area, areaTxt );
    printf( "Area = %s\n", areaTxt );

    to_text( peri, periTxt );
    printf( "Perimeter = %s\n", periTxt );
    return 0;
}

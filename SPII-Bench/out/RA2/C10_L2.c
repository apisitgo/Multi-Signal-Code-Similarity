/* ------------------------------------------------------------
   Programming Fundamentals - Lab exercise
   Task    : Geometry Area #1 - Rectangle
   Student : <student id> <full name>
   ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* whole numbers are printed without decimals, others with 2 */
static void to_text( double num, char *out ) {
    if ( !isinf( num ) && num == floor( num ) )
        sprintf( out, "%lld", (long long)num );
    else
        sprintf( out, "%.2f", num );
}

int main( void ) {
    double width = 0, height = 0;
    scanf( "%lf", &width );
    scanf( "%lf", &height );

    char areaTxt[64], periTxt[64];

    to_text( width * height, areaTxt );
    printf( "Area = %s\n", areaTxt );

    to_text( 2 * ( width + height ), periTxt );
    printf( "Perimeter = %s\n", periTxt );
    return 0;
}

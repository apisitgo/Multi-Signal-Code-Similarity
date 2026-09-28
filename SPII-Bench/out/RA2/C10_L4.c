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

/* print "<label> = <value>" using the formatting rule above */
static void print_labeled( const char *label, double value ) {
    char txt[TXT_LEN];
    to_text( value, txt );
    printf( "%s = %s\n", label, txt );
}

static double rect_area( double w, double h ) { return w * h; }
static double rect_peri( double w, double h ) { return 2 * ( w + h ); }

int main( void ) {
    double width = 0, height = 0;

    scanf( "%lf", &width );
    scanf( "%lf", &height );

    print_labeled( "Area", rect_area( width, height ) );
    print_labeled( "Perimeter", rect_peri( width, height ) );
    return 0;
}

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
    int whole = 0;
    if ( !isinf( num ) )
        whole = ( num == floor( num ) );
    if ( !whole ) {
        snprintf( out, TXT_LEN, "%.2f", num );
        return;
    }
    snprintf( out, TXT_LEN, "%lld", (long long)num );
}

/* print "<label> = <value>" using the formatting rule above */
static void print_labeled( const char *label, double value ) {
    char txt[TXT_LEN];
    to_text( value, txt );
    fputs( label, stdout );
    fputs( " = ", stdout );
    puts( txt );
}

int main( void ) {
    double width = 0, height = 0;
    const char *labels[2] = { "Area", "Perimeter" };
    int k;

    scanf( "%lf %lf", &width, &height );

    for ( k = 0; k < 2; k++ ) {
        double value;
        switch ( k ) {
        case 0:  value = height * width; break;
        default: value = ( width + height ) * 2; break;
        }
        print_labeled( labels[k], value );
    }
    return 0;
}

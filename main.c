#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char **argv ) {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  color c;
  c.red = 0;
  c.green = 45;
  c.blue = 200;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  clear_screen( s );
  
  /*  add_circle( edges, 250, 250, 100, .01 );
      draw_lines ( edges, s, c ); */

  add_curve( edges, 100, 100, 200, 200, 250, 250, 300, 300, .01, 1);
  draw_lines ( edges, s, c );

  /*  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
  parse_file( "stdin", transform, edges, s );*/

  //  printf(" BOO \n ");
  
  display( s ) ;
  save_ppm( s, "curves.ppm" );
  
  free_matrix( transform );
  free_matrix( edges );
}  

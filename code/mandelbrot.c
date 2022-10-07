#include <stdio.h>

int main() {

  int w, h;     // width and height of the image
  int i, j;     // pixels
  double x, y;          // z = x + iy 
  double x_new, y_new;  // iterative update
  double a, b;  // current point in complex plane

  int n, max_iter;

  w = 100;
  h = 100;

  /* Open the file and write the header. */
  FILE * fp = fopen("./prova","a+");
  char *comment="# Mandelbrot set";/* comment should start with # */

  /*write ASCII header to the file*/
  fprintf(fp,
          "P6\n# Mandelbrot, xmin=%lf, xmax=%lf, ymin=%lf, ymax=%lf, maxiter=%d\n%d\n%d\n%d\n",
          xmin, xmax, ymin, ymax, maxiter, xres, yres, (maxiter < 256 ? 256 : maxiter));

  unsigned char *image = malloc(w*h);

  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      
      // iteration over the point
      for (n = 0; n < max_iter && (x*x+y*y<4.0); n++)
        x_new = x*x - y*y + a;
        y_new = 2*x*y + b;
        x = x_new;
        y = y_new;
      

        image[j+i*w] = 0;

  printf("%d", w*w);

  fclose(fp);

  return 0;
}

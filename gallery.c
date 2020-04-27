#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gallery.h"

int frame;

int main(){
  /* printf("push\nmove\n250 250 0\nrotate\nx 40\nscale\n3 3 3\n"); */
  /* printf("parseobj\nobj_files/Round_rosette_022.obj\n"); */
  /* printf("display\n"); */

  printf("push\n");
  printf("move\n 250 250 0\nrotate\nx -40\nrotate\ny -15\nrotate\nz -15\nscale\n1.5 1.5 1.5\n");
  frame = 0;
  int i;
  double r;
  for(r=0;r<M_PI;r+=(M_PI/25)){
	double rot = 50 * (1 - cos(r) );
	gen_box(rot);
	save_frame();
  }
  for(i=0;i<8;i++){
	save_frame();
  }
  for(r = 0.0; r < 7*M_PI/5; r+=(M_PI/45) ){
  	/* printf("display\n"); */
	double rot = 50 * sin(5*r)/(2.5*r);
	gen_box(rot);
	save_frame();
  }
  
}

void gen_box(double wheel_theta) {
  printf("clear\n");
  printf("box\n-100 100 0 200 200 50\n");
  printf("push\n");
  printf("rotate\nx 90\n");
  printf("scale\n1.5 1.5 1.5\n");
  /* double rot = -90.0 * (1+cos(r)); */
  printf("rotate\ny %lf\n", wheel_theta);
  printf("parseobj\nobj_files/Round_rosette_022.obj\n");
  printf("pop\n");
}

void save_frame() {
  printf("save\nframes/gallery%03d.png\n",frame);
  printf("$frame %d complete\n",frame);
  frame++;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  /* printf("push\nmove\n250 250 0\nrotate\nx 40\nscale\n3 3 3\n"); */
  /* printf("parseobj\nobj_files/Round_rosette_022.obj\n"); */
  /* printf("display\n"); */

  printf("push\n");
  printf("move\n 250 250 0\nrotate\nx -40\nrotate\ny -15\nrotate\nz -15\nscale\n1.5 1.5 1.5\n");
  int frame = 0;
  int i;
  double r;
  for(r=0;r<M_PI;r+=(M_PI/50)){
	printf("clear\n");
	printf("push\n");
	printf("move\n0 125 0\n");
	printf("box\n 0 0 0 100 250 50\n");
	printf("pop\n");
	printf("push\n");
	printf("move\n-100 125 0\n");
	printf("box\n0 0 0 100 250 50\n");
	printf("push\n");
	printf("move\n50 -50 -10\n");
	printf("rotate\nx 90\n");
	double rot = 50 * (1 - cos(r) );
	/* double rot = 90 * sin(10*r)/(5*r); */
	printf("rotate\ny %lf\n", rot);
	printf("parseobj\nobj_files/Round_rosette_022.obj\n");
	printf("pop\n");
	printf("pop\n");
	printf("save\nframes/gallery%03d.png\n",frame);
	printf("$frame %d complete\n",frame);
	frame++;
  }
  for(i=0;i<15;i++){
  	printf("save\nframes/gallery%03d.png\n",frame);
  	printf("$frame %d complete\n",frame);
  	frame++;
  }
  for(r = 0.0; r < M_PI; r+=(M_PI/90) ){
  	printf("clear\n");
  	printf("push\n");
  	printf("move\n0 125 0\n");
  	printf("box\n 0 0 0 100 250 50\n");
  	printf("pop\n");
  	printf("push\n");
  	printf("move\n-100 125 0\n");
  	printf("box\n0 0 0 100 250 50\n");
  	printf("push\n");
  	printf("move\n50 -50 -10\n");
  	printf("rotate\nx 90\n");
  	/* double rot = -90.0 * (1+cos(r)); */
  	double rot = 50 * sin(5*r)/(3*r);
  	printf("rotate\ny %lf\n", rot);
  	printf("parseobj\nobj_files/Round_rosette_022.obj\n");
  	printf("pop\n");
  	printf("pop\n");
  	/* printf("display\n"); */
  	printf("save\nframes/gallery%03d.png\n",frame);
  	printf("$frame %d complete\n",frame);
  	frame++;
  }
  for(i=0;i<15;i++){
  	printf("save\nframes/gallery%03d.png\n",frame);
  	printf("$frame %d complete\n",frame);
  	frame++;
  }
}

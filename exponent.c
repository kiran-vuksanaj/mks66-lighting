#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("push\n");
  printf("move\n250 250 0\n");
  int n;
  for( n = 0; n < 100; n++ ){
	printf("sphere\n0 0 0 200\n");
	printf("save\nframes/frame%02d.png\n",n);
	printf("$completed %d\n",n);
	printf("clear\nexp++\n");
  }

}

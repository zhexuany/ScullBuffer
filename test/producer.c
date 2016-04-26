#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define ITEM_SIZE 32

int main(int argc, char **argv){
  int fd;
  int num_items;
  int i;
  char *color;

  if(argc != 3){
    perror("Usage: ./producer <number_items> <color>\n");
    return 0;
  }

  if((fd = open("/dev/scullbuffer", O_WRONLY)) == -1){
    perror("PRODUCER: Cannot open scullbuffer for writing\n");
    return 0;
  }

  char product[ITEM_SIZE];

  num_items = atoi(argv[1]);
  color = argv[2];
  for(i = 0; i < num_items; i++){
    sprintf(product, "%s%020d", color, i);
    printf("PRODUCER: Writing item %s\n", product);
    if(write(fd, product, ITEM_SIZE) == 0){
      printf("PRODUCER: Write failed\n");
      return 0;
    }
    usleep(100000); // sleep for 100ms
  }

  close(fd);
}


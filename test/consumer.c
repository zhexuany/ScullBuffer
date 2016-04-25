#include <stdio.h>
#include <fcntl.h>

#define ITEM_SIZE 32

int main(int argc, char **argv){
  int fd;
  int num_items;
  int i;

  if(argc != 2){
    perror("Usage: ./consumer <number_items>\n");
    return 0;
  }

  if((fd = open("/dev/scullbuffer", O_RDONLY)) == -1){
    perror("CONSUMER: Cannot open scullbuffer for writing\n");
    return 0;
  }

  char product[ITEM_SIZE];

  num_items = atoi(argv[1]);
  for(i = 0; i < num_items; i++){
    if(read(fd, product, ITEM_SIZE) == 0){
      printf("CONSUMER: Nothing to read\n");
      return 0;
    }
    else
      printf("CONSUMER: Reading item %s\n", product);
    usleep(100000); //sleep for 100ms
  }
  close(fd);
}

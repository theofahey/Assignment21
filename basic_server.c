#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  while(1){
  from_client = server_handshake( &to_client );
  char buffer[BUFFER_SIZE];
  while(read(from_client,buffer,BUFFER_SIZE)){
    printf("read from_client\n");
    int i,hold,length;
    length = strlen(buffer);
    for (i = 0; i < length/2;i++){
     hold = buffer[i];
     buffer[i] = buffer[length - i - 1];
     buffer[length - i - 1] = hold;
      }
    write(to_client,buffer,BUFFER_SIZE);
}
}
}

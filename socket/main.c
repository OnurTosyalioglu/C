#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>
#define PORT 8000

struct Data{
  char *file_name;
  char *message;
};

typedef struct Data data;

void *write_file(void *);
void *read_file(void *);

int main(int argc, const char *argv[])
{
  int server_fd,     // socket file descriptor
      new_socket,    // socket
      valread,       // read value
      opt,           // option
      address_len,   // address length
      protocol;      // socket protocol

  char *message,
       *address,
       *file_name;

  struct sockaddr_in address;

  return 0;
}

void *write_file(void *data)
{

}

void *read_file(void *data)
{

}

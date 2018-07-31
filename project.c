#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

void read_file(const char* ,char );
void read_folder(const char* ,char );
void read_args(int ,const char ** );
void error_arg_number();

void file_size(struct stat);
void file_permissions(struct stat);
void last_status_change(struct stat);
void last_file_access(struct stat);
void last_file_modification(struct stat);
void inode(struct stat);
void links(struct stat);

int main(int argc, const char *argv[])
{
    read_args(argc,argv);
    return 0;
}

void read_args(int argc, const char *argv[])
{
  char flag, dash;

  if(argc != 3)
  {
    error_arg_number();
  }
  else
  {
    if(strlen(argv[2]) != 2)
    {
      error_arg_number();
    }
    else
    {
      dash = argv[2][0];
      flag = argv[2][1];

      if(dash == '-' && (flag == 'y' || flag == 'm' || flag == 'w' || flag == 'd') )
      {
        read_folder(argv[1], flag);
      }
      else
      {
        printf("Invalid flag !!\n");
      }
    }
  }
}

void read_folder(const char *folder_name,char timeline )
{
  DIR *d;
  struct dirent *dir;

  d = opendir(folder_name);

  if(d)
  {
    while( (dir = readdir(d)) != NULL)
    {
      if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 )
      {
        printf("%s : ", dir->d_name);
        read_file(dir->d_name, timeline);
      }
        //read_file(dir->d_name, timeline);
    }
  }
}

void read_file(const char *file_name, char timeline)
{
  struct stat status;
  int fd;
  fd = open(file_name, O_RDONLY);

  if(fstat(fd, &status))
  {
    printf("%s\n", ctime(&status.st_atime));
  }

}

void file_size(struct stat status)
{
  printf("%lld ", status.st_size);
}

void file_permissions(struct stat status)
{
  printf( (S_ISDIR(status.st_mode)) ? "d" : "-");
  printf( (status.st_mode & S_IRUSR) ? "r" : "-");
  printf( (status.st_mode & S_IWUSR) ? "w" : "-");
  printf( (status.st_mode & S_IXUSR) ? "x" : "-");
  printf( (status.st_mode & S_IRGRP) ? "r" : "-");
  printf( (status.st_mode & S_IWGRP) ? "w" : "-");
  printf( (status.st_mode & S_IXGRP) ? "x" : "-");
  printf( (status.st_mode & S_IROTH) ? "r" : "-");
  printf( (status.st_mode & S_IWOTH) ? "w" : "-");
  printf( (status.st_mode & S_IXOTH) ? "x" : "-");
}

void last_status_change(struct stat status)
{
  printf("%s ", ctime(&status.st_ctime));
}

void last_file_access(struct stat status)
{
  printf("%s ", ctime(&status.st_atime));
}

void last_file_modification(struct stat status)
{
  printf("%s ", ctime(&status.st_mtime));
}

void inode(struct stat status)
{
  printf("%llu ", status.st_ino);
}

void links(struct stat status)
{
  printf("%d ", status.st_nlink);
}

void error_arg_number()
{
  printf("Invalid number of parameters!!\n");
}

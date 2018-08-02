/**
 *  This program is sample about stat
 *  system call to list last modification
 *  time of folder or file.
 *
 *  flags
 *  d: file modified in last day
 *  w: file modified in last week
 *  m: file modified in last month
 *  y: file modified in last year
 *
 *  Compile
 *  ---------------
 *  gcc ls.c -o lsm
 *
 *  Run
 *  ---------------
 *  ./lsm [file|folder] -[d|w|m|y]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int check_args(int ,int);
void last_file_access(struct stat);
void last_file_modification(struct stat);
void last_status_change(struct stat);
void permissions(struct stat);
void size(struct stat);
void inode(struct stat);
void links(struct stat);
int get_current_year();
int get_current_month();
int get_current_day();
int get_year(struct stat);
int get_month(struct stat);
int get_day(struct stat);
void parse_args(int ,const char* []);
void read_dir(char, const char*);
void write_file_status(char,const char*);
void total_info(struct stat,const char*);

int main(int argc, const char *argv[])
{

  parse_args(argc,argv);

  return 0;
}

void parse_args(int argc, const char *argv[])
{
  if(check_args(argc,3))
  {
    if(argv[2][0] == '-' && (argv[2][1] == 'd'|| argv[2][1] == 'm' || argv[2][1] == 'y'|| argv[2][1] == 'w'))
    {
      read_dir(argv[2][1],argv[1]);
    }
    else
    {
      printf("Invalid flag !!\n");
    }
  }
  else
  {
    printf("Invalid arguments !!\n");
  }
}

void read_dir(char flag, const char *file_name)
{
  DIR *d;
  struct dirent *dir;
  d = opendir(file_name);

  if(d)
  {
    while((dir = readdir(d)) != NULL )
    {
      write_file_status(flag ,dir->d_name);
    }
  }
  else
  {
    write_file_status(flag ,file_name);
  }
}

void write_file_status(char flag,const char *name)
{
  struct stat status;

  int current_year = get_current_year();
  int current_month = get_current_month();
  int current_day = get_current_day();

  stat(name, &status);

  int file_year = get_year(status);
  int file_month = get_month(status);
  int file_day = get_day(status);

  if(flag == 'm')
  {
    if(current_month-1 == file_month && file_year == current_year)
    {
      if(current_day < file_day)
      {
        total_info(status,name);

      }
    }

    if(current_month == file_month && file_year == current_year)
    {
      total_info(status,name);

    }
  }

  if(flag == 'y')
  {
    if(current_year-1 <= file_year)
    {
      total_info(status,name);
    }
  }

  if(flag == 'd')
  {
    if(current_day == 1)
    {
      if((file_day == 30 || file_day == 31) && file_month == current_month-1 && file_year == current_year)
      {
        total_info(status,name);
      }
    }
    else
    {
      if(file_day >= current_day && file_month == current_month && file_year == current_year )
      {
        total_info(status,name);
      }
    }
  }

  if(flag == 'w')
  {
    if(current_day > 7)
    {
      if(current_day-7 <= file_day && file_month == current_month && file_year == current_year )
      {
        total_info(status,name);
      }
    }
    else
    {
      if((current_day + 31)-7 <= file_day && file_month == current_month-1 && file_year == current_year)
      {
        total_info(status,name);
      }
    }
  }
}

void total_info(struct stat status,const char *name)
{
   // permission, number of hard links,
   // user id, group id, size, last file modification time
   permissions(status);
   links(status);
   struct passwd *pw = getpwuid(status.st_uid);
   struct group *gr = getgrgid(status.st_gid);
   printf("%s ",pw->pw_name);
   printf("%s ",gr->gr_name);
   size(status);
   last_file_modification(status);
   printf("%s\n", name);
}

int check_args(int argc, int expected)
{
  return (argc == expected) ? 1 : 0;
}

void last_file_access(struct stat status)
{
  printf("%s ", ctime(&status.st_atime));
}

void last_file_modification(struct stat status)
{
  printf("%s ", ctime(&status.st_mtime));
}

void last_status_change(struct stat status)
{
  printf("%s ", ctime(&status.st_ctime));
}

void permissions(struct stat status)
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
  printf(" ");
}

void size(struct stat status)
{
  printf("%ld ", status.st_size/1024*1024);
}

void inode(struct stat status)
{
  printf("%ld ", status.st_ino);
}

void links(struct stat status)
{
  printf("%ld ", status.st_nlink);
}

int get_current_year()
{
  time_t now;
  struct tm *current;
  char buffer[100];

  time(&now);
  current = localtime(&now);

  strftime(buffer, sizeof(buffer), "%Y", current);

  return atoi(buffer);
}

int get_current_month()
{
  time_t now;
  struct tm *current;
  char buffer[100];

  time(&now);
  current = localtime(&now);

  strftime(buffer, sizeof(buffer), "%m", current);

  return atoi(buffer);
}

int get_current_day()
{
  time_t now;
  struct tm *current;
  char buffer[100];

  time(&now);
  current = localtime(&now);

  strftime(buffer, sizeof(buffer), "%d", current);

  return atoi(buffer);
}

int get_year(struct stat status)
{
  struct tm *file_time;
  char buffer[100];

  file_time = localtime(&status.st_mtime);

  strftime(buffer, sizeof(buffer) ,"%Y",file_time);

  return atoi(buffer);
}

int get_month(struct stat status)
{
  struct tm *file_time;
  char buffer[100];

  file_time = localtime(&status.st_mtime);

  strftime(buffer, sizeof(buffer) ,"%m",file_time);

  return atoi(buffer);
}

int get_day(struct stat status)
{
  struct tm *file_time;
  char buffer[100];

  file_time = localtime(&status.st_mtime);

  strftime(buffer, sizeof(buffer) ,"%d",file_time);

  return atoi(buffer);
}

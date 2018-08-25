#include <stdio.h>

int file_exists(const char * );
void file_read(FILE **, const char *);
void file_write(FILE **, const char *);
void file_append(FILE **, const char *);
void file_read_plus(FILE **, const char *);
void file_write_plus(FILE **, const char *);
void file_append_plus(FILE **, const char *);

int main(int argc, const char *argv[])
{

    return 0;
}

int file_exists(const char *path)
{
    FILE *fp;
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        return 0;
    }
    else
    {
        fclose(fp);
        return 1;
    }
}

void file_read(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "r");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }

}

void file_write(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "w");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }
}

void file_append(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "a");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }
}

void file_read_plus(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "r+");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }
}

void file_write_plus(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "w+");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }

}

void file_append_plus(FILE **fp, const char *path)
{
    (*fp) = fopen(path, "a+");

    if ( (*fp) == NULL )
    {
        perror("Error :");
    }

}

void write_string(FILE *fp, const char *str)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "%s", str) < 0 )
        {
            perror("Error :");
        }
    }
}

void write_int(FILE *fp, int i)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "%d", i) < 0 )
        {
            perror("Error :");
        }
    }
}

void write_float(FILE *fp, float f)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "%f", f) < 0 )
        {
            perror("Error :");
        }
    }
}

void write_double(FILE *fp, double d)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "%lf", d) < 0 )
        {
            perror("Error :");
        }
    }
}

void write_char(FILE *fp, char c)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "%c", c) < 0 )
        {
            perror("Error :");
        }
    }
}

void write_ln(FILE *fp)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "\n") < 0 )
        {
            perror("Error :");
        }
    }
}

void write_tab(FILE *fp)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, "\t" ) < 0)
        {
            perror("Error :");
        }
    }
}

void write_space(FILE *fp)
{
    if ( fp == NULL )
    {
        perror("Error :");
    }
    else
    {
        if ( fprintf(fp, " ") < 0 )
        {
            perror("Error :");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

void create_char_array_1D(char **, int);
void destroy_char_array_1D(char **);
void fill_char_array_1D(char **, int, char );

void create_char_array_2D(char ***, int, int);
void destroy_char_array_2D(char ***, int);
void fill_char_array_2D(char ***, int, int, char );

void create_char_array_3D(char ****, int, int, int);
void destroy_char_array_3D(char ****, int, int);
void fill_char_array_3D(char ****, int, int, int, char );

void allocation_error();
void size_error();

int main(int argc, const char *argv[])
{

    return 0;
}

void size_error()
{
    printf("Invalid size !!\n");
}
void allocation_error()
{
    printf("Cannot allocate memory !!\n");
}

void create_char_array_1D(char **ptr, int x)
{
    if (( (*ptr) = (char *)malloc(x * sizeof(char)) ) == NULL)
    {
        allocation_error();
    }
}

void destroy_char_array_1D(char **ptr)
{
    free(*ptr);
}

void fill_char_array_1D(char **ptr, int x, char ch)
{
    int i;

    if (x < 1)
    {
        size_error();
    }
    else
    {
        for (i = 0; i < x; i++)
        {
            (*ptr)[i] = ch;
        }
    }
}

void create_char_array_2D(char ***ptr, int x, int y)
{
    if (x < 1 || y < 1)
    {
        size_error();
    }
    else
    {
        if (((*ptr) = (char ** )malloc(x * sizeof(char *))) == NULL)
        {
            allocation_error();
        }
        else
        {
            int i;

            for (i = 0; i < x; i++)
            {
                create_char_array_1D(&(*ptr)[i], y);
            }
        }

    }
}

void destroy_char_array_2D(char ***ptr, int x)
{
    if (x < 1)
    {
        size_error();
    }
    else
    {
        int i;

        for (int i = 0; i < x; i++)
        {
            destroy_char_array_1D(&(*ptr)[i]);
        }
    }
}

void fill_char_array_2D(char ***ptr, int x, int y, char ch)
{
    if (x < 1 || y < 1)
    {
        size_error();
    }
    else
    {
        int i;

        for (i = 0; i < x; i++)
        {
            fill_char_array_1D(&(*ptr)[i], y, ch);
        }

    }
}

void create_char_array_3D(char ****ptr, int x, int y, int z)
{
    if (x < 1 || y < 1 || z < 1)
    {
        size_error();
    }
    else
    {
        if (((*ptr) = (char ***)malloc(x * sizeof(char **) ) ) == NULL)
        {

            allocation_error();
        }
        else
        {
            int i;

            for (i = 0; i < x; i++)
            {
                create_char_array_2D(&(*ptr)[i], y, z);
            }
        }
    }
}

void destroy_char_array_3D(char ****ptr, int x, int y)
{
    if (x < 1 || y < 1 )
    {
        size_error();
    }
    else
    {
        int i;

        for (int i = 0; i < x; i++)
        {
            destroy_char_array_2D(&(*ptr)[i], y);
        }
    }
}

void fill_char_array_3D(char ****ptr, int x, int y, int z, char ch)
{
    if (x < 1 || y < 1 || z < 1)
    {
        size_error();
    }
    else
    {
        int i;

        for (i = 0; i < x; i++)
        {
            fill_char_array_2D(&(*ptr)[i], y, z, ch);
        }

    }
}

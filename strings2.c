#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRING_ISGRAPHIC(c) \
      (   (c) >= 0 \
       && (c) <= 255 \
       && ((c) == '\t' || isprint (c) \
           ) \
      )

int main(int argc, char **argv)
{
    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // buffer to store potential string of yet insufficient length
    unsigned char *buf = (unsigned char*) malloc(4);
    // number of printable chars processed so far
    char count = 0;

    int c = 0;
    while ((c = fgetc(fp)) != EOF) {
        if ( STRING_ISGRAPHIC(c) )
        {
            if (count > 3)
            {
                printf("%c", c);
                continue;
            }
            buf[count] = (unsigned char) c;
            count++;
            if (count == 4)
            {
                printf("%c%c%c%c", buf[0], buf[1], buf[2], buf[3]);
            }
        }
        else
        {
            // print newline if a string has been printed
            if (count > 3)
                printf("\n");
            count = 0;
        }
    }

    free(buf);
    fclose(fp);

    return 0;
}

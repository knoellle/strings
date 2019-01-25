#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }

    // preallocate a buffer for the getline call
    char* line = (char*) malloc(512);
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp("STATIC", line, read-1) == 0) {
            continue;
        }
        int c = 0;
        for (int i=0; i<read-1; i++) {
            if (line[i] >= 48 && line[i] < 127)
                c++;
        }
        c *= 100;

        if (c/(read-1) > 60)
            printf("%s",line);
    }

    free(line);

    fclose(fp);

    return 0;
}

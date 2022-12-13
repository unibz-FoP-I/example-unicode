#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

#define SIZE_INCREMENT 10

size_t read_lines(FILE *fp, char *(**lines))
{
    size_t nLines = 0;
    size_t maxLines = SIZE_INCREMENT;

    if (!(*lines))
    {
        *lines = malloc(maxLines * sizeof(char **));
    }

    char *lineBuf = NULL;
    size_t bufSize = 0;
    ssize_t lineLength = 0;

    for (size_t i = 0; (lineLength = getline(&lineBuf, &bufSize, fp)) != -1; i++)
    {
        if (i >= maxLines)
        {
            maxLines += SIZE_INCREMENT;
            char **tmp = realloc(*lines, maxLines * sizeof(char **));
            if (!tmp)
            {
                perror("realloc");
                break;
            }
            *lines = tmp;
        }


        char *newLinePtr = strchr(lineBuf, '\n');
        if (newLinePtr)
        {
            *newLinePtr = 0;
        }


        char *newLine = malloc((lineLength + 1) * sizeof(char));
        if (!newLine)
        {
            perror("realloc");
            break;
        }

        memccpy(newLine, lineBuf, 0, lineLength);
        newLine[lineLength] = 0;
        strcpy(newLine, lineBuf);
        (*lines)[i] = newLine;

        nLines++;
    }

    free(lineBuf);
    return nLines;
}

void printLines(char **lines, size_t size) {
    if (lines) {
        for (size_t i = 0; i < size; i++)
        {
            puts(lines[i]);
        }
    }
}

void printUTFLines(char **lines, size_t size) {
    if (lines) {
        for (size_t i = 0; i < size; i++)
        {
            printf("%3zu[%3zu]: %s\n", strlen(lines[i]), utf8len(lines[i]), lines[i]);
        }
    }
}

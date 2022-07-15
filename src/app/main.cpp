#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

void hexDump(size_t, void*, int);

int main(int argc, char* argv[])
{
    //if (argc != 2)
    //{
    //    exit(EXIT_FAILURE);
    //}
    //FILE* myfile = fopen(argv[1], "rb");
    FILE* myfile = fopen("data/example.txt", "rb");
    if (myfile == 0)
    {
        fprintf(stderr, "%s: failed to open file '%s' for reading\n", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[SIZE];
    size_t n;
    size_t offset = 0;
    while ((n = fread(buffer, 1, SIZE, myfile)) > 0)
    {
        hexDump(offset, buffer, n);
        if (n < SIZE)
            break;
        offset += n;
    }

    fclose(myfile);
    return 0;
}

void hexDump(size_t offset, void* addr, int len)
{
    int i;
    unsigned char bufferLine[17];
    unsigned char* pc = (unsigned char*)addr;

    for (i = 0; i < len; i++)
    {
        if ((i % 16) == 0)
        {
            if (i != 0)
                printf(" %s\n", bufferLine);
            // Bogus test for zero bytes!
            //if (pc[i] == 0x00)
            //    exit(0);
            printf("%08zx: ", offset);
            offset += (i % 16 == 0) ? 16 : i % 16;
        }

        printf("%02x", pc[i]);
        if ((i % 2) == 1)
            printf(" ");

        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
        {
            bufferLine[i % 16] = '.';
        }
        else
        {
            bufferLine[i % 16] = pc[i];
        }

        bufferLine[(i % 16) + 1] = '\0';
    }

    while ((i % 16) != 0)
    {
        printf("  ");
        if (i % 2 == 1)
            putchar(' ');
        i++;
    }
    printf(" %s\n", bufferLine);

}
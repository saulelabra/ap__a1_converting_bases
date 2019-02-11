#include "stdio.h"
#include "unistd.h"

//argc==number of arguments
//argv==array of strings

int main(int argc, char *argv[])
{
    int c = 0;
    int iflag=0, oflag=0;
    char * inBase = NULL;
    char * outBase = NULL;

    printf("The variables are declared\n");

    while((c=getopt(argc, argv, "i:o:")) != -1)//getopt() returns -1 when there are no more options to process
    {
        printf("Enters getopt() loop\n");
        switch (c){
            case 'i':
                inBase = optarg;//optarg variable contains the argument
                printf("the input base is: %s\n", inBase);
                break;
            case 'o':
                outBase = optarg;
                printf("the output base is: %s\n", outBase);
                break;
        }
    }

    return 0;
}
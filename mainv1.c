#include "stdio.h"
#include "unistd.h"

//argc==number of arguments
//argv==array of strings

int main(int argc, char *argv[])
{
    int c = 0;
    int iflag=0, oflag=0;
    int inIndex=0, outIndex=0;
    char * inBase = NULL;
    char * outBase = NULL;

    printf("The variables are declared\n");

    //When getopt() is called the following variables are filled:
    //int optopt
    //int optind --> stores the index of the argument
    //char * optarg --> stores the argument

    while((c=getopt(argc, argv, "i:o:")) != -1)
    {
        printf("Enters getopt() loop\n");
        switch (c){
            case 'i':
                inBase = optarg;
                inIndex = optind;
                printf("the input base is: %s with index=%d\n", inBase, optind);
                break;
            case 'o':
                outBase = optarg;
                outIndex = optind;
                printf("the output base is: %s with index=%d\n", outBase, optind);
                break;
        }
    }

    return 0;
}
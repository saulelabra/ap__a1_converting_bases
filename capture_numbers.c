#include "stdio.h"
#include "unistd.h"

//argc==number of arguments
//argv==array of strings

int max(int first, int second)
{
    if(first > second)
    {
        return first;
    }else{
        if(second > first)
        {
            return second;
        }else{
            if(first== second)
            {
                return first;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int c = 0;
    int iflag=0, oflag=0, errorFlag=0;
    int iIndex=0, oIndex=0;
    char * inBase = NULL;
    char * outBase = NULL;
    
    int lastArg=0;
    char * numArray[15];
    int numCounter=0;

    printf("The variables are declared\n");

    while((c=getopt(argc, argv, "i:o:")) != -1)
    {
        printf("Enters getopt() loop\n");
        switch (c){
            case 'i':
                iflag = 1;
                iIndex=optind;
                inBase = optarg;
                printf("the input base is: %s with index=%d\n", inBase, iIndex);
                break;
            case 'o':
                oflag = 1;
                oIndex=optind;
                outBase = optarg;
                printf("the output base is: %s with index=%d\n", outBase, oIndex);
                break;
            case '?':
                errorFlag = 1;
                printf("The input option is not valid, try again!\n");
                break;
        }
    }
    
    if(errorFlag == 1)
    {
        return -1;
    }else{
        if(iflag*oflag != 1)
        {
            printf("One of the base arguments is missing, Try again!\n");
        }else{
            lastArg=max(iIndex, oIndex);
            printf("the last argument is %d\n", lastArg);

            for(int i=lastArg; i<argc; i++)
            {
                numArray[i-lastArg] = argv[i];
            }
        }
    }

    int numElements = argc-lastArg;
    printf("There are %d numbers:\n", numElements);
    for(int i=0; i<numElements; i++)
    {
        printf("%d: %s\n", i, numArray[i]);
    }

    return 0;
}
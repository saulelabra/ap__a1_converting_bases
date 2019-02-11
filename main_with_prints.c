#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define NUMLENGTH 15

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
    char * inNumArray[NUMLENGTH];
    char outNumArray[NUMLENGTH][NUMLENGTH];
    int numCounter=0;

    //printf("The variables are declared\n");

    while((c=getopt(argc, argv, "i:o:")) != -1)
    {
        //printf("Enters getopt() loop\n");
        switch (c){
            case 'i':
                iflag = 1;
                iIndex=optind;
                inBase = optarg;
                //printf("the input base is: %s with index=%d\n", inBase, iIndex);
                break;
            case 'o':
                oflag = 1;
                oIndex=optind;
                outBase = optarg;
                //printf("the output base is: %s with index=%d\n", outBase, oIndex);
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
            //printf("the last argument is %d\n", lastArg);

            for(int i=lastArg; i<argc; i++)
            {
                inNumArray[i-lastArg] = argv[i];
            }
        }
    }

    int numElements = argc-lastArg;
    //printf("There are %d numbers:\n", numElements);
    for(int i=0; i<numElements; i++)
    {
        //printf("%d: %s\n", i, inNumArray[i]);
    }

    //Converting number

    char * decimal[NUMLENGTH*2];

    for(int i=0; i<numElements; i++)
    {
        int j=0;
        int slength = strlen(inNumArray[i]);
        int totalValue=0;
        
        //Converting to decimal
        while(inNumArray[i][j]!='\0')
        {
            int currDigVal;
            if((int)inNumArray[i][j] >= 65 && (int)inNumArray[i][j] <= 90)
            {
                currDigVal = ((int)inNumArray[i][j])-55;
                if(currDigVal >= atoi(inBase))
                {
                    printf("The input number is not in the specified base\n");
                    return -1;
                }else{
                    totalValue += currDigVal*pow(atoi(inBase), slength-j-1);
                    //printf("base=%d exp=%d totalValue=%d\n", currDigVal, slength-j-1, totalValue);
                }
            }else{
                if((int)inNumArray[i][j] >= 48 && (int)inNumArray[i][j] <= 57)
                {
                    currDigVal = ((int)inNumArray[i][j])-48;
                    if(currDigVal >= atoi(inBase))
                    {
                        printf("The input number is not in the specified base\n");
                        return -1;
                    }else{
                        totalValue += currDigVal*pow(atoi(inBase), slength-j-1);
                        //printf("base=%d exp=%d totalValue=%d\n", currDigVal, slength-j-1, totalValue);
                    }
                }else{
                    printf("Character '%c' is not valid, Try again!\n", inNumArray[i][j]);
                    return -1;
                }
            }
            //printf("Digit: %c\tValue: %d\n", inNumArray[i][j], currDigVal);
            j++;
        }

        printf("The number in decimal is: %d\n", totalValue);

        //Converting to output base
        int quotient=totalValue;
        int outBaseInt = atoi(outBase);
        j=0;
        while(quotient!=0)
        {
            if(j>=NUMLENGTH)
            {
                printf("Memory overload!\n");
                return -1;
            }

            int DigVal=0;
            DigVal = quotient%outBaseInt;
            //printf("Digit is: %d\n", DigVal);

            //Converting value to char digit
            if(DigVal<10)
            {
                outNumArray[i][j] = DigVal + '0';
                //printf("Saves char %c at position %d\n", outNumArray[i][j], j);
            }else{
                if(DigVal >= 10 && DigVal<=26)
                {
                    int numofchar = (DigVal-10)+65;
                    outNumArray[i][j] = numofchar;
                    //printf("Saves char %c at position %d\n", outNumArray[i][j], j);
                }
            }

            quotient = floor(quotient/outBaseInt);
            //printf("Quotient is %d\n", quotient);
            j++;
        }

        printf("The converted number is: ");
        for(int k=strlen(outNumArray[i])-1; k>=0; k--)
        {
            printf("%c", outNumArray[i][k]);
        }
        printf("\n");    
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int i;
    double p[6];

    if(argc != 7)
    {
        printf("ERROR: Invalid number of arguments");
        return -1;
    }
    for(i=1; i < argc; i ++)
    {
        //get the parameter
        p[i-1] = strtod(argv[i],NULL);
    }

    ///assume that you have a function that works on these parameters
    ///and following is the resulting parameters that go on the file

    //in the very end write the results to a file
    FILE* f;
    f = fopen("results","w");
    for(i = 0; i < 6; i ++)
        fprintf(f,"%Lf\n",p[i]);
    fclose(f);
    return 0;
}

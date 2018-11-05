//#include <iostream>
#include <stdio.h>


const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ","))
    {
        printf("NUM:%d\t--NUM%d\n", num, --num);
        if (!--num)
            return tok;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    FILE *pFile;
    int array[7];
    int num = 1;
    //open file
    pFile = fopen("test.csv", "r");

    if (pFile != NULL) {

        char line[1024];
        while (fgets(line, 1024, pFile)) {
            char* tmp = strdup(line);

            printf("Token:%s\n", getfield(tmp, 1));
            printf("Token:%s\n", getfield(tmp, 2));
            array[0] = getfield(tmp, 1);
            printf("Array[0]:%s\n", array[0]);
            array[1] = getfield(tmp, 2);
            printf("Array[1]:%s\n", array[1]);
            array[2] = getfield(tmp, 3);
            printf("Array[2]:%s\n", array[2]);
            array[3] = getfield(tmp, 4);
            printf("Array[3]:%s\n", array[3]);
            array[4] = getfield(tmp, 5);
            printf("Array[4]:%s\n", array[4]);
            array[5] = getfield(tmp, 6);
            printf("Array[5]:%s\n", array[5]);
            array[6] = getfield(tmp, 7);
            printf("Array[6]:%s\n", array[6]);
            //free(tmp);
        }

        //for (int i=0; i<(sizeof(array)/sizeof(array[0])); i++) {
        //    printf("Array[%d]: %d\n", i, array[i]);
        //}
        fclose(pFile);

    } else {
        printf("Could Not open file.\n");
    }
}

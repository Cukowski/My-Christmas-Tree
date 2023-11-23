#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main(int argc, char ** argv)
{
    int tree_size = atoi(argv[1]);

    int rows = 4; // for size 1
    int start = 1; // for size 1
    int decrease = 2; 
    int max_width = 7; // for size 1

    // CALCULATE THE WIDTH (MAX)
    for (int i = 1; i <= tree_size; i++) 
    {
        rows = 3 + i;

        if (i < tree_size)
            start += (rows - decrease) * 2;
        else 
            max_width = start + 2 * rows;
        if (rows % 2 != 0)
            decrease++;
    }

    if (DEBUG) printf("max height: %d\n", max_width);

    // CALCULATE AND PRINT THE STARS
    start = 1;
    decrease = 2;

    for (int i = 1; i <= tree_size; i++) 
    {
        rows = 3 + i;

        for (int k = 0; k < rows; k++) 
        {
            int length_of_leaves = start + 2 * k;

            if (DEBUG) printf("%d", length_of_leaves);

            for (int j = 0; j < (max_width - length_of_leaves) / 2 - 1; j++)
                printf(" ");
            for (int j = 0; j < length_of_leaves; j++)
                printf("*");

            printf("\n");
        }

        // this helps changing start point every loop
        if (i < tree_size)
            start += (rows - decrease) * 2;
        if (rows % 2 != 0)
            decrease++;

    }

    // print the stem

    for (int i = 0; i < tree_size; i++)
    {
        int length_of_space = 1;

        if ((max_width - tree_size) % 2 == 0)
            length_of_space = (max_width - tree_size) / 2 - 1;
        else
            length_of_space =  (max_width - tree_size) / 2;

        if (DEBUG) printf("%d", length_of_space);

        for (int  j = 0; j < length_of_space; j++)
            printf(" ");
        for (int  j = 0; j < tree_size; j++)
            printf("|");

        printf("\n");
    }

}
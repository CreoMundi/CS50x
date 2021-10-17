#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height = get_int("Height: ");

    //check the condition, repeat if incorrect
    while (height<1 || height>8){
        height = get_int("Height: ");
    }

    //loop for a single line, repeated "height" times
    for (int i=0; i<height; i++) {

        //for a first row of blanks
        for (int j=height-i; j>1; j--) {
            printf(" ");
        }

        //for a first row of blocks
        for (int k=0; k<=i; k++){
            printf("#");
        }

        printf("  ");

        //for a second row of blocks
        for(int l=0; l<=i; l++) {
            printf("#");
        }

        //for a second row of blanks
        
//        for (int m=height-i; m>1; m--) {
//            printf(" ");
//        }

        printf("\n");
    }
}
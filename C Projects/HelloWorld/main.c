#include <stdio.h>
#include <stdlib.h>

int remap(int x, int in_min, int in_max, int out_min, int out_max){
    return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int main()
{
    int guess;


    int genderNum;
    printf("Enter your gender, Man or Woman.\nEnter 0 for Man or 1 for Woman:\n");
    scanf("%d", &genderNum );

    if (genderNum == 1)
        {printf("You are a Woman\n");}
    else
        {printf("You are a Man\n");}
    printf("Enter a number 0 to 5:\n");
    scanf("%d", &guess );
    /*printf("%d\n", guess);*/
    if (guess == 3){
        printf("You got it\n");
        return 0;
    }
    else
        {printf("Nope\n");}

    while (guess != 3){

        printf("Enter a number 0 to 5:\n");
        scanf("%d", &guess );

        if (guess == 3){
            printf("You got it!\n");
        }
        else
            {printf("Nope\n");}
    }
    if (genderNum == 1)
        {printf("You are superwoman\n");}
    else {printf("You are a superman\n");}
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

char input[8] = {0};
unsigned int myvar = 0;

int main() {

    unsigned int secret = 0;

    printf("BSS\n");
    printf("+-----------------------+-------------------------+\n");
    printf("|myvar: %16d|address: %16p|\n", myvar, &myvar);
    printf("|-----------------------|-------------------------+\n");
    printf("|input: %16s|address: %16p|\n", input, &input);
    printf("+-----------------------+-------------------------+\n");
    printf("\n");
    printf("I am going to copy 12 (0xc) bytes of input into input. Can you modify myvar?\n");

    while (1) {

        char raw_in[14] = {0};
        for (int i = 0; i < 8; i++) {
            input[i] = 0;
        }

        fgets(raw_in, 14, stdin);

        for (int i = 0; i < 12; i++) {
            if (raw_in[i] == '\n') {
                break;
            } else if (raw_in[i] < 'a' || raw_in[i] > 'z') {
                printf("Only lowercase letters allowed!\n");
                break;
            }
            input[i] = raw_in[i];
        }

        printf("\n");
        printf("+-----------------------+-------------------------+\n");
        printf("|myvar: %16d|address: %16p|\n", myvar, &myvar);
        printf("|-----------------------|-------------------------+\n");
        printf("|input: %16s|address: %16p|\n", input, &input);
        printf("+-----------------------+-------------------------+\n");
        printf("\n");

        if (myvar == 0) {
            printf("sorry, try again!\n");

        } else if (myvar == secret) {
            printf("You win!\nCheck the notes to get your flag!\n");
            break;

        } else if (secret == 0) {

            printf("Good job! You changed it!\n");

            secret = myvar;

            secret >>= 4;
            secret <<= 4;

            if (myvar < 1337 && secret == myvar) {
                secret = secret * 0xe57a21;
                printf("Excellent!\n");
                printf("Now try to change myval to this secret value: %d (0x%x)\n", secret, secret);
            
            } else {
                printf("Unfortunately myvar is either too big or or doesn't meet the other requirement. Try again.\n");
                secret = 0;
                myvar = 0;
            }

        } else {
            printf("Sorry, try again!\n");
            printf("Remember the secret value is: %d (0x%x)\n", secret, secret);
        }
    }
    return 0;
}
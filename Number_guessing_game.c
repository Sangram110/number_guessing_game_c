#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome_message() {
    printf("==============================================================\n");
    printf("welcome to the number guessing game!\n");
    printf("==============================================================\n");
    printf("I've selected a number between 1 and 100. Can you guess it?\n");
    printf("you have a maximum of 10 attempts to guess the number.\n");
    printf("good luck!\n");
    printf("==============================================================\n");
}

void goodbye_message(){
    printf("==============================================================\n");
    printf("thank you for playing the number guessing game!\n");
    printf("goodbye!\n");
    printf("==============================================================\n");
}

void hint_message(int guess, int number) {
    if (guess < number) {
        printf("hint: the number is higher than your guess.\n");
    } else if (guess > number) {
        printf("hint: the number is lower than your guess.\n");
    }
}

void invalid_input_message() {
    printf("invalid input! please enter a number between 1 and 100.\n");
}

void display_results(int number, int attempts) {
    printf("the number was: %d\n", number);
    printf("you made %d attempts.\n", attempts);
}

int main() {
    int number, guess, attempts = 0;
    srand(time(0)); // seeding the random number generator 
    number = rand() % 100 + 1; // generating a random number between 1 and 100
    
    welcome_message();
    invalid_input_message();
    do {
        if (attempts > 10){
            printf("you've made maximum %d attempts. better luck next time!\n", attempts);
            break;
        }
        printf("enter you guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess < number){
            hint_message(guess, number);
        } else if (guess > number ){
            hint_message(guess, number);
        } else {
            printf("congratulations! you guessed the number %d in %d attempts.\n", number, attempts);
            break;
        }
    } while (1);
    goodbye_message();
    return 0;
}
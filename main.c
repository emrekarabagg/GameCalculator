/* Emre Karabağ 210201053*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main() {


    char operators[3] = {'+', '-', '*'};
    int booleanNumber = 1;
    srand(time(0));
    char guess[4];
    float correctGuess = 0;
    float wrongGuess = 0;
    float successRate;
    float numOfQuestion = 0;
    int result;


    while (booleanNumber) {
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        int operatorIndex = rand() % 3;

        if (operatorIndex == 1) {
            num2 = rand() % num1 + 1;
            result = num1 - num2;
            numOfQuestion++;
        } else {
            if (operatorIndex == 0) {
                result = num1 + num2;
                numOfQuestion++;
            } else {
                result = num1 * num2;
                numOfQuestion++;
            }
        }
        printf("%d %c %d = %c\n", num1, operators[operatorIndex], num2, '?');
        printf("enter calculation result\n");
        scanf("%s", &guess);
        if (strcmp(guess,"x")!=0) {
            if (atoi(guess) == result) {
                correctGuess++;
                printf("Correct!\n");
            } else {
                wrongGuess++;
                printf("Wrong! Correct answer is %d\n", result);
            }
        } else {

            numOfQuestion--;
            booleanNumber = 0;
        }
    }

    successRate = (correctGuess/numOfQuestion)*100;
    printf("%.0f question: %.0f correct, %.0f wrong answers\n", numOfQuestion,correctGuess, wrongGuess);
    printf("Success rate is %.0f%%.",  successRate);


    return 0;
}

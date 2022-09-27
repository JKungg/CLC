#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // Declare Variables for - Developer Name and UserInput
    char name[20];
    char userInput;

    // Print Calculator Welcome Message
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: ");
    scanf("%s", name);
    printf("Version: 1\n");
    printf("Date: 2022-09-26\n");
    printf("----------------------------------------------------------\n\n");

    // Calculator Main Menu
    printf("Select one of the following items:\n"
           "B) - Binary Mathematical Operations, such as addition and subtraction.\n"
           "U) - Unary Mathematical Operations, such as square root, and log.\n"
           "A) - Advances Mathematical Operations, using variables, arrays.\n"
           "V) - Define variables and assign them values.\n"
           "E) - Exit\n");

    // While Loop to keep calculator running until user wants to exit.
    while(toupper(userInput) != 'E'){

        // Read User Selection
        printf("\n----------------------------------------------------------"
               "\nPlease select your option ( B , U , A , V , E ) : ");
        scanf("%s", &userInput);

        // Convert userInput to uppercase.
        if(toupper(userInput) == 'B'){

            // Read num1, num2 and operator
            double num1, num2;
            char operator;
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the operation ( + , - , * , /) : ");
            scanf("%s", &operator);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);

            // Switch case for the 4 types of possible operations
            switch(operator){
                case '+' :
                    printf("The result is %lf", (num1+num2));
                    break;

                case '-' :
                    printf("The result is %lf", (num1-num2));
                    break;

                case '*' :
                    printf("The result is %lf", (num1*num2));
                    break;

                case '/' :
                    // Must make sure it is not trying to be divided by 0.
                    if(num2!=0.00){
                        printf("The result is %lf", (num1/num2));
                        break;
                    } else{
                        printf("You cannot divide by 0!");
                        break;
                    }

                    // Default case if user doesn't select one of the operators available.
                default :
                    printf("\nSorry I don't have enough knowledge to serve you at this time.");
            }
        }
    }


    return 0;
}

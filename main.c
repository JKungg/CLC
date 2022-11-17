#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int binaryOperation(char operator, float num1, float num2){
    switch(operator){
        case '+' :
            // Calculate sum and print it.
            printf("The result is %f", (num1+num2));
            break;

        case '-' :
            // Calculate subtraction and print it.
            printf("The result is %f", (num1-num2));
            break;

        case '*' :
            // Calculate product and print it.
            printf("The result is %f", (num1*num2));
            break;

            // Calculate Quotient and print it
        case '/' :
            // Must make sure it is not trying to be divided by 0.
            if(num2!=0.00){
                printf("The result is %f", (num1/num2));
                break;
            } else{
                printf("You cannot divide by 0!");
                break;
            }
            // Calculate Remainder
        case '%':
            printf("The result is %f", remainderf(num1,num2));
            break;

            // Calculate Power
        case 'P':
            printf("The result is %f", pow(num1,num2));
            break;

            // Calculate Maximum
        case 'X':
            printf("The result is %f", fmaxf(num1,num2));
            break;

            // Calculate Minimum
        case 'I':
            printf("The result is %f", fminf(num1,num2));
            break;

            // Default case if user doesn't select one of the operators available.
        default :
            printf("\nSorry I don't have enough knowledge to serve you at this time.");
    }
}


float a,b,c,d,e;

int main() {
    // Declare Variables for - Developer Name and UserInput
    char name[20];
    char userInput;

    // Print Calculator Welcome Message
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: ");
    // Read Developer Name
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

        // Show Option selection message
        printf("\n----------------------------------------------------------"
               "\nPlease select your option ( B , U , A , V , E ) : ");
        // Read userInput
        scanf("%s", &userInput);

        // Convert userInput to uppercase.
        // If userInput is 'B'
        if(toupper(userInput) == 'B'){

            // Declare required variables
            float num1, num2;
            char operator;
            printf("Please enter the first number:");
            // Read num1
            scanf("%f", &num1);
            printf("Please enter the operation ( + , - , * , /, %, P, X, I) :");
            // Read operator
            scanf("%s", &operator);
            printf("Please enter the second number:");
            // Read num2
            scanf("%f", &num2);

            //Call Binary Operation Function.
            binaryOperation(operator,num1,num2);

            // If statement for option U
        } else if(userInput=='U'){
            float num;
            char operator;
            printf("Enter a number:");
            scanf("%f", &num);
            printf("Enter an operator(S for square root, L for logarithm (logx), E for exponentiation (e!), C for the smallest integer value greater than or equal to x, or F for the largest integer value greater than or equal to x.)");
            scanf("%s", &operator);

            // Switch for the different possible operands.
            switch(operator){

                // Case for square root.
                case 'S':
                    // Check to see if it is a positive number
                    if(num >= 0){
                        printf("The result is: %f", sqrtf(num));
                        break;
                    } else{
                        printf("Invalid input!");
                        break;
                    }

                    // Case for Logarithm
                case 'L':
                    if(num>0){
                        printf("The result is: %f", logf(num));
                        break;
                    } else{
                        printf("Invalid input!");
                        break;
                    }

                    // Case for exponentiation
                case 'E':
                    printf("The result is: %f", expf(num));
                    break;

                    // Case for smallest integer value greater than or equal to x
                case 'C':
                    printf("The result is: %f", ceilf(num));
                    break;

                    // Case for largest integer value greater than or equal to x
                case 'F':
                    printf("The result is: %f", floorf(num));
                    break;

            }
            // If statement for option V
        } else if(userInput=='V'){
            //Define user inputted variable and scan it.
            char userVar;
            printf("Enter a variable letter (a-e):");
            scanf("%c", &userVar);

            switch(userVar){
                case 'a':
                    printf("Enter a value for the variable %c",userVar);
                    scanf("%f",&a);
                    break;
                case 'b':
                    printf("Enter a value for the variable %c",userVar);
                    scanf("%f",&b);
                    break;
                case 'c':
                    printf("Enter a value for the variable %c",userVar);
                    scanf("%f",&c);
                    break;
                case 'd':
                    printf("Enter a value for the variable %c",userVar);
                    scanf("%f",&d);
                    break;
                case 'e':
                    printf("Enter a value for the variable %c",userVar);
                    scanf("%f", &e);
                    break;
                default:
                    printf("Invalid variable name!");
            }

            // If statement for option A
        } else if(userInput=='A'){
            char selection;
            printf("Select an option (B; Binary Operation, U; Unary Operation, E; Exit):");
            scanf("%c",&selection);
            if(selection=='B'){

            }
        }

    }


    return 0;
}

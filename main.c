#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function for checking if user input is a valid input(float).
int checkValidFloat(float num){
    // Declaring Requried Variables
    char buffer[100];
    char *endptr;
    if(fgets(buffer, sizeof(buffer), stdin) == NULL)
        return -1;
    num = strtod(buffer, &endptr);
    if((*endptr == '\0') || (isspace(*endptr) != 0))
        return 1;
    else
        return 0;
}

float getNum(){
    float num;
    scanf("%f", &num);
    while(checkValidFloat(num) == 0){
        printf("Invalid Input. Enter a number: ");
        scanf("%f", &num);
    }
    return num;
}

// Function for Binary Operations
float binaryOperation(char operator, float num1, float num2){
    switch(operator){
        case '+' :
            // Calculate sum and print it.
            printf("The result is %f", (num1+num2));
            return(num1+num2);

        case '-' :
            // Calculate subtraction and print it.
            printf("The result is %f", (num1-num2));
            return(num1-num2);

        case '*' :
            // Calculate product and print it.
            printf("The result is %f", (num1*num2));
            return(num1*num2);

            // Calculate Quotient and print it
        case '/' :
            // Must make sure it is not trying to be divided by 0.
            if(num2!=0.00){
                printf("The result is %f", (num1/num2));
                return(num1/num2);
            } else{
                printf("You cannot divide by 0!");
                break;
            }
            // Calculate Remainder
        case '%':
            printf("The result is %f", remainderf(num1,num2));
            return(remainderf(num1,num2));

            // Calculate Power
        case 'P':
            printf("The result is %f", pow(num1,num2));
            return(powf(num1,num2));

            // Calculate Maximum
        case 'X':
            printf("The result is %f", fmaxf(num1,num2));
            return(fmaxf(num1,num2));

            // Calculate Minimum
        case 'I':
            printf("The result is %f", fminf(num1,num2));
            return(fminf(num1,num2));

            // Default case if user doesn't select one of the operators available.
        default :
            printf("\nSorry I don't have enough knowledge to serve you at this time.");
    }
}

// Function for Unary Operations
float unaryOperation(char operator, float num){
    // Switch for the different possible operands.
    switch(operator){

        // Case for square root.
        case 'S':
            // Check to see if it is a positive number
            if(num >= 0){
                printf("The result is: %f", sqrtf(num));
                return(sqrtf(num));
            } else{
                printf("Invalid input!");
                break;
            }

            // Case for Logarithm
        case 'L':
            if(num>0){
                printf("The result is: %f", logf(num));
                return logf(num);
            } else{
                printf("Invalid input!");
                break;
            }

            // Case for exponentiation
        case 'E':
            printf("The result is: %f", expf(num));
            return expf(num);

            // Case for smallest integer value greater than or equal to x
        case 'C':
            printf("The result is: %f", ceilf(num));
            return ceilf(num);

            // Case for largest integer value greater than or equal to x
        case 'F':
            printf("The result is: %f", floorf(num));
            return floorf(num);

    }
}

float a = 0, b = 0, c = 0, d =0, e = 0;

int main() {
    // Declare Variable for UserInput
    char userInput = 0;

    // Print Calculator Welcome Message
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Jack Dilkens");
    printf("Version: 2\n");
    printf("Date: 2022-11-18\n");
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
            char op;
            //Get operator and numbers from user.
            printf("Please enter the first number:");
            num1 = getNum();
            while(op!='+' && op!='-' && op!='*'&& op!='/' && op!='%' && op!= 'P' && op!='X' && op!='I'){
                printf("Please enter the operation ( + , - , * , /, %, P, X, I) :");
                scanf("%s", &op);
            }
            printf("Please enter the second number:");
            num2= getNum();

            //Call Binary Operation Function.
            binaryOperation(op,num1,num2);

            // If statement for option U
        } else if(toupper(userInput)=='U'){
            //Declare required variables.
            float num;
            char op;
            //Get operator and number from user.
            printf("Enter a number:");
            num = getNum();
            while(op!='S' && op!='L' && op!='E'&& op!='C' && op!='F'){
                printf("Enter an operator(S for square root, L for logarithm (logx), E for exponentiation (e!), C for the smallest integer value greater than or equal to x, or F for the largest integer value greater than or equal to x.)");
                scanf("%s", &op);
            }

            //Call Unary Operation Function.
            unaryOperation(op,num);

            // If statement for option V
        } else if(toupper(userInput)=='V'){
            //Define user inputted variable and scan it.
            char userVar;
            printf("Enter a variable letter (a-e):");
            scanf("%s", &userVar);
            while(userVar != 'a' && userVar != 'b' && userVar != 'c' && userVar != 'd' && userVar != 'e'){
                printf("Invalid variable. Enter a variable letter (a-e): ");
                scanf("%s", &userVar);
            }

            switch(userVar){
                case 'a':
                    printf("Enter a number for the variable %c:",userVar);
                    a = getNum();
                    break;
                case 'b':
                    printf("Enter a number for the variable %c:",userVar);
                    b = getNum();
                    break;
                case 'c':
                    printf("Enter a number for the variable %c:",userVar);
                    c = getNum();
                    break;
                case 'd':
                    printf("Enter a number for the variable %c:",userVar);
                    d = getNum();
                    break;
                case 'e':
                    printf("Enter a number for the variable %c:",userVar);
                    e = getNum();
                    break;
                default:
                    printf("Invalid variable name!");
            }

            // If statement for option A
        } else if(userInput=='A'){
            char selection;
            printf("Select an option (B; Binary Operation, U; Unary Operation, E; Exit):");
            scanf("%s",&selection);
            if(selection=='B'){

            }
        }

    }


    return 0;
}

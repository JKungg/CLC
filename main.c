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
    //Check if it's a float and return 1 if True
    if((*endptr == '\0') || (isspace(*endptr) != 0))
        return 1;
    //If it is not a true float return 0.
    else
        return 0;
}

float getNum(){
    float num;
    scanf("%f", &num);
    while(checkValidFloat(num) != 1){
        printf("Invalid Input. Enter a number: ");
        scanf("%f", &num);
    }
    return num;
}

float a = 0, b = 0, c = 0, d =0, e = 0;

float getVar(char var){
    switch(var){
        case 'a':
            return a;
        case 'b':
            return b;
        case 'c':
            return c;
        case 'd':
            return d;
        case 'e':
            return e;
    }
}

float varOrNum(){
    char in, varA;
    //Ask user if they want to input a variable or number
    printf("Would you like to input a variable(V) or a number(N)?: ");
    scanf("%s", &in);
    // Loop until proper input is entered
    while(toupper(in)!='V'&& toupper(in)!='N'){
        printf("Invalid input, would you like to input a Variable(V) or Number(N)?: ");
        scanf("%s", &in);
    }

    // Variable choice
    if(toupper(in)=='V'){
        //Get operator and variables from user.
        printf("Please enter the first variable:");
        scanf("%s", &varA);
        //Loop until proper input is entered.
        while(varA != 'a' && varA != 'b' && varA != 'c' && varA != 'd' && varA != 'e'){
            printf("Invalid variable. Enter a variable letter (a-e): ");
            scanf("%s", &varA);
        }
        return getVar(varA);
    }
        // Number choice
    else if(toupper(in)=='N'){
        //Get operator and numbers from user.
        printf("Please enter a number:");
        return getNum();
    }
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
            while(num2==0){
                printf("Denominator cannot be 0, enter another number: ");
                num2 = getNum();
            }
            printf("The result is %f", (num1/num2));
            return(num1/num2);
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
            while(num<0){
                printf("Number cannot be negative, enter another number: ");
                num = getNum();
            }
            // Check to see if it is a positive number
            if(num >= 0){
                printf("The result is: %f", sqrtf(num));
                return(sqrtf(num));
            } else{
                printf("You cannot get the squareroot of a negative number!");
                break;
            }

            // Case for Logarithm
        case 'L':
            while(num<=0){
                printf("Number cannot be negative or zero, enter another number: ");
                num = getNum();
            }
                printf("The result is: %f", logf(num));
                return logf(num);

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


int main() {
    // Declare Variable for UserInput
    char userInput = 0;

    // Print Calculator Welcome Message
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Jack Dilkens\n");
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
            char op = 0;
            //Get operator and numbers from user.
            printf("Please enter the first number:");
            num1 = getNum();
            //Loop until proper input is entered.
            while(op!='+' && op!='-' && op!='*'&& op!='/' && op!='%' && op!= 'P' && op!='X' && op!='I'){
                printf("Please enter the operation ( + , - , *, /, %%, P, X, I) :");
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
            char op = 0;
            //Get operator and number from user.
            printf("Enter a number:");
            num = getNum();
            //Loop until proper input is entered.
            while(op!='S' && op!='L' && op!='E'&& op!='C' && op!='F'){
                printf("\nEnter an operator...\nS for square root...\nL for logarithm (logx)...\nE for exponentiation (e!)...\nC for the smallest integer value greater than or equal to x...\nF for the largest integer value greater than or equal to x...: ");
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
            //Loop until proper input is entered.
            while(userVar != 'a' && userVar != 'b' && userVar != 'c' && userVar != 'd' && userVar != 'e'){
                printf("Invalid variable. Enter a variable letter (a-e): ");
                scanf("%s", &userVar);
            }
            // Switch for assigning a value to the variable.
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
        } else if(toupper(userInput)=='A'){
            char selection = 0;
            while(toupper(selection)!='E'){
                printf("\nSelect an option (B; Binary Operation, U; Unary Operation, E; Exit):");
                scanf("%s",&selection);

                // Advanced Binary Operations
                if(toupper(selection)=='B'){
                    // Declare required variables
                    char op = 0;
                    float num1, num2;
                    // Assign the value of the variable or number to num1
                    num1 = varOrNum();

                    //Get Operator
                    //Loop until proper input is entered.
                    while(op!='+' && op!='-' && op!='*'&& op!='/' && op!='%' && op!= 'P' && op!='X' && op!='I'){
                        printf("Please enter the operation ( + , - , * , /, %%, P, X, I) :");
                        scanf("%s", &op);
                    }
                    // Assign the value of the variable or number to num2
                    num2 = varOrNum();

                    //Call Binary Operation Function.
                    binaryOperation(op,num1,num2);

                }
                // Advanced Unary Operation
                else if(toupper(selection)=='U'){
                    //Declare required variables.
                    float num;
                    char op = 0, var = 0;

                    // Assign the value of the variable or number to num
                    num = varOrNum();

                    while(op!='S' && op!='L' && op!='E'&& op!='C' && op!='F'){
                        printf("Enter an operator...\nS for square root...\nL for logarithm (logx)...\nE for exponentiation (e!)...\nC for the smallest integer value greater than or equal to x...\nF for the largest integer value greater than or equal to x...: ");
                        scanf("%s", &op);
                    }
                    // Call unary operation
                    unaryOperation(op,num);
                }
            }
        }
    }
    return 0;
}

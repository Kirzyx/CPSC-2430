//Ryan Luo
//Assignment 2
#include <cmath>
#include <iostream>

//prototypes
int mysterySequence(int n);
int tennisBalls(int n);
std::string decToBase2(int n);
bool isDivisibleBy7(int n);
double ramanujan(int depth, int maxDepth);
void runTests();

int main() {
    //get input from user
    int input;
    while(true) {
        //menu
        std::cout << std::endl << "Welcome to the recursion assignment. What would you like to test?" 
            << std::endl
            << "1. mystery sequence" << std::endl
            << "2. tennisBalls" << std::endl
            << "3. decToBase2" << std::endl
            << "4. isDivisibleBy7" << std::endl
            << "5. ramanujan" << std::endl
            << "6. run tests" << std::endl
            << "7. Exit" << std::endl << std::endl;

        std::cin >> input;

        while(input > 7 || input < 1) {
            //input validation
                std::cout << "Invalid input. Please enter a number between 1 and 7: " << std::endl;
                std::cin >> input;
        }
        switch (input) {
            case 1: {
                std::cout << std::endl << "Task 1: Mystery Sequence" << std::endl << "Insert a number: ";
                std::cin >> input;
                std::cout << std::endl << mysterySequence(input) << std::endl;
                break;
            }
            case 2: {
                std::cout << std::endl << "Task 2: Tennis balls" << std::endl << "Insert a number: ";
                std::cin >> input;
                std::cout << std::endl << tennisBalls(input) << std::endl;
                break;
            }
            case 3: {
                std::cout << std::endl << "Task 3: Decimal to Binary " << std::endl << "Insert a number: ";
                std::cin >> input;
                std::cout << std::endl << decToBase2(input) << std::endl;
                break;
            }
            case 4: {
                std::cout << std::endl << "Task 4: Divisibility by 7 " << std::endl << "Insert a number: ";
                std::cin >> input;
                if(isDivisibleBy7(input)){
                    std::cout << input << " is divisible by 7" << std::endl;
                } else {
                    std::cout << input << " is not divisible by 7" << std::endl;
                }
                break;
            }
            case 5: {
                int depth;
                std::cout << std::endl << "Ramanujan. Enter integer depth: ";
                std::cin >> depth;
                double result = ramanujan(0,depth);
                double infinite_result = ramanujan(0, 100);
                std::cout << std::endl << "Result at depth " << depth << ": " << result << std::endl
                    << "Result at infinite depth: " << infinite_result;
                break;
            }
            case 6: {
                //run tests
                runTests();
                break;
            }
            case 7: {
                // Exit program
                return 0;
            }
        }
    }
    return 0;
}

//Takes integer n and returns nth number in the sequence
int mysterySequence(int n) {
    //base cases
    if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 3;
    } else if (n == 0) {
        return 0;
    } else {
        //recurive case, returns the product of the 2 prvious terms in the sequence
        return mysterySequence(n-1) * mysterySequence(n-2);
    }
}

//takes an integer and returns total number of tennis balls in a pyramid with
//n levels
int tennisBalls(int n) {
    //base cases
    if (n == 1) {
        return 1;
    } else if(n == 0){
        return 0;
    }else {
        //recursive case, returns the number of balls 
        return tennisBalls(n-1) + n*n;   
    }
}

//convert decimal to binary
std::string decToBase2(int n) {
    //base case
    if (n == 0) {
        return "0";
    } else if (n == 1) {
        return "1";
    } else {
        //returns binary string of n/2 then append n%2 to it
        return decToBase2(n / 2) + std::to_string(n % 2);
    }
}

//solves for ramanujan's sequence
double ramanujan(int depth, int maxDepth) {
    //base case
    if(depth == maxDepth) {
        return (depth+1)*sqrt(6+depth);
    } else {
        //recursive case
         return (depth+1)*sqrt((6+depth) + ramanujan(depth + 1, maxDepth));
    }
   
}

bool isDivisibleBy7(int n) {
    //base case
    if (n < 10) {
        return (n == 0 || n == 7);
    } 
    int lastDigit = (n % 10)*2;
    int remmainingNumber = n/10;
    int result = remmainingNumber - lastDigit;
    //recursive case, compute the result by subtracting double the last digit from
    //the remaining number then check if it is divisible by 7
    return isDivisibleBy7(result);
}

void runTests() {
    //test mysterySequence
    std::cout << "Testing mysterySequence" << std::endl;
    std::cout << "mysterySequence(0): " << mysterySequence(0) << std::endl;
    std::cout << "mysterySequence(1): " << mysterySequence(1) << std::endl;
    std::cout << "mysterySequence(4): " << mysterySequence(4) << std::endl;
    std::cout << "mysterySequence(7): " << mysterySequence(7) << std::endl;
    std::cout << std::endl;

    //test tennisBalls
    std::cout << "Testing tennisBalls" << std::endl;
    std::cout << "tennisBalls(0): " << tennisBalls(0) << " tennis balls" << std::endl;
    std::cout << "tennisBalls(1): " << tennisBalls(1) << " tennis balls" << std::endl;
    std::cout << "tennisBalls(3): " << tennisBalls(3) << " tennis balls" << std::endl;
    std::cout << "tennisBalls(10): " << tennisBalls(10) << " tennis balls" << std::endl;
    std::cout << std::endl;

    //test decToBase2
    std::cout << "Testing decToBase2" << std::endl;
    std::cout << "decToBase2(0): " << decToBase2(0) << std::endl;
    std::cout << "decToBase2(1): " << decToBase2(1) << std::endl;
    std::cout << "decToBase2(13): " << decToBase2(13) << std::endl;
    std::cout << "decToBase2(32): " << decToBase2(32) << std::endl;
    std::cout << "decToBase2(321): " << decToBase2(321) << std::endl;
    std::cout << std::endl;

    //test isDivisibleBy7
    std::cout << "Testing isDivisibleBy7" << std::endl;
    std::cout << "isDivisibleBy7(1): " << isDivisibleBy7(1) << std::endl;
    std::cout << "isDivisibleBy7(7): " << isDivisibleBy7(7) << std::endl;
    std::cout << "isDivisibleBy7(31): " << isDivisibleBy7(31) << std::endl;
    std::cout << "isDivisibleBy7(1073): " << isDivisibleBy7(1073) << std::endl;
    std::cout << "isDivisibleBy7(1729): " << isDivisibleBy7(1729) << std::endl;
    std::cout << std::endl;

    //test ramanujan
    std::cout << "Testing ramanujan" << std::endl;
    std::cout << "ramanujan(0, 1): " << ramanujan(0, 1) << std::endl;
    std::cout << "ramanujan(0, 3): " << ramanujan(0, 3) << std::endl;
    std::cout << "ramanujan(0, 10): " << ramanujan(0, 10) << std::endl;
}
//Ryan Luo
//lab2.cpp
#include <chrono>
#include <iostream>
using namespace std::chrono;

//function prototypes
int** iterativePascal(int degree);
int recursiveBico(int degree, int index);
int** recursivePascal(int degree);
void print(int** pascal, int degree, int coef);
int bico(int** pascal, int degree, int index);
void deletePascal(int** pascal, int degree);

int main() {
    int degree;
    int coef;
    std::cout << "Degree of binomial: ";
    //User inputs degree
    std::cin >> degree;
    //User inputs coefficient
    std::cout << "Index of coefficient: ";
    std::cin >> coef;
    //input validation
    while(coef > degree) {
        std::cout << "Index cannot be larger than degree" << std::endl;
        std::cout << "Index of coefficient: ";
        std::cin >> coef;
    }

    std::cout << std::endl;
    
    //assign variables to iterative and recursive pascal
    int** iter_pascal = iterativePascal(degree);
        
    int** recur_pascal = recursivePascal(degree);
        
    std::cout << std::endl << std::endl;

    //print triangles
    std::cout << "Lab 1, iterative pascal triangle: " << std::endl;
    print(iter_pascal, degree, coef);
    
    std::cout << std::endl << std::endl;

    std::cout << "Lab 2, recursive pascal triangle: " << std::endl;
    print(recur_pascal, degree, coef);

    std::cout << std::endl << std::endl;

    //deallocate memory
    deletePascal(iter_pascal, degree);
    deletePascal(recur_pascal, degree);

    return 0;
}

//returns the binomial of the chosen index
int bico(int** pascal, int degree, int index) {
    int bico = pascal[degree][index];
    return bico;
}
int** iterativePascal(int degree) {
    int new_degree = degree+1;
    //dyanmically allocate memory for 2d array for the size of degree
    int** pascal = new int*[new_degree];
    for(int i  = 0; i < new_degree; i++) {
        pascal[i] = new int[new_degree];
    }
    
    //for loop to fill add 1s to the beginning of each collumn
    for(int r = 0; r < new_degree; r++) {
        pascal[r][0] = 1;
    }
    
    //for loop that starts at index 1 to go through each collumn except for the first one
    for(int r = 1; r < new_degree; r ++) {
        //iterate up to the current row
        for(int c = 1; c <= r; c++) {
            //add the values of the top left and top right of the previous row
            pascal[r][c] = pascal[r-1][c-1] + pascal [r-1][c];
        }
    }

    return pascal;
}

//recursive function to find binomial
int recursiveBico(int degree, int index) {
    //base case
    if(index == 0 || index == degree) {
        return 1;
    }
    //recursive case
    return recursiveBico(degree - 1, index - 1) + recursiveBico(degree - 1, index);
}

//recursive function for recursive pascal
int** recursivePascal(int degree) {
    //allocate memory
    int** pascal = new int*[degree+1];
    
    for(int i = 0; i <= degree; i++){
        pascal[i] = new int[degree];
    }
    //add values with recursiveBico
    for(int r = 0; r <= degree; r ++){
        for(int c = 0; c <= r; c++){
            pascal[r][c] = recursiveBico(r, c);
        }
    }

    return pascal;
}

//function to print pascal triangle
void print(int** pascal, int degree, int coef) {
    //for loop to iterate through triangle
    for (int r = 0; r < degree+1; r++) {
        for (int c = 0; c <= r; c++) {
            std::cout << pascal[r][c] << " ";
        }
     std::cout << std::endl;
    }

    std::cout << "The result is " << bico(pascal, degree, coef);
    std::cout << std::endl;
}

//Deallocate memory
void deletePascal(int** pascal, int degree) {

    for(int i = 0; i < degree; i++) {
        delete[] pascal[i];
    }
    delete[] pascal;
}
//Ryan Luo
//lab1.cpp

#include <iostream>

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
    //dyanmically allocate memory for 2d array for the size of degree
    int** pascal = new int*[degree];
    for(int i  = 0; i < degree; i++) {
        pascal[i] = new int[degree];
    }
    
    //for loop to fill add 1s to the beginning of each collumn
    for(int r = 0; r < degree; r++) {
        pascal[r][0] = 1;
    }
    
    //for loop that starts at index 1 to go through each collumn except for the first one
    for(int r = 1; r < degree; r ++) {
        //iterate up to the current row
        for(int c = 1; c <= r; c++) {
            //add the values of the top left and top right of the previous row
            pascal[r][c] = pascal[r-1][c-1] + pascal [r-1][c];
        }
    }

    //for loop to print the triangle
    for(int r = 0; r < degree; r++) {
        //iterate to the collumn to the current row
        for(int c = 0; c <= r; c++) {
            std::cout << pascal[r][c] << " ";
        }
        std::cout << std::endl;
    }

    //get result
    std::cout << std::endl;
    std::cout << "The result is " << pascal[degree-1][coef];
    std::cout << std::endl;

    //deallocate memory
    for (int i = 0; i < degree; i++) {
        delete[] pascal[i];
    }
    delete[] pascal;

    return 0;
}

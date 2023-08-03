//Ryan Luo
//lab3.cpp

#include <iostream>
#include <string>
#include "ShelterBST.h"


int main(){
    ShelterBST tree;

    tree.insertPet ("Zelda", 5);
    tree.insertPet ("Link", 7);
    tree.insertPet ("Joe", 4);
    tree.insertPet ("Nathan", 3);
    tree.insertPet ("Ryan", 1);
    tree.insertPet ("Oreo", 2);
    tree.insertPet ("Luna", 6);
    tree.insertPet ("Charlie", 8);
    tree.insertPet ("Bella", 9);
    tree.insertPet ("Zeus", 10);

    std::cout << std::endl;
    
    std::cout << std::endl << "Inorder Display" << std::endl;

    //inorder display;
    tree.inorderDisplay();

    std::cout << std::endl;
    
    std::cout << std::endl << "Preorder Display" << std::endl;

    //preorder display
    tree.preorderDisplay();

    std::cout << std::endl;

    std::cout << std::endl << "Postorder Display" << std::endl;

    //postorder display
    tree.postorderDisplay();

    std::cout << std::endl;

    //succesful search
    tree.searchPet(7);
    
    std::cout << std::endl;

    //unsuccesful search
    tree.searchPet(100);
    
     std::cout << std::endl;

    return 0;
}

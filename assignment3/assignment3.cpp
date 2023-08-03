//Ryan Luo
//Assignment 3

#include <iostream>
#include "ShelterBST.h"

void test(ShelterBST& tree);

int main() {

    ShelterBST shelter;
    ShelterBST shelterTest;

    while (true) {
        std::cout << "Welcome to my implementation of ShelterBST" << std::endl
                  << "Please choose the operation you want: " << std::endl
                  << "1. Insert a node" << std::endl
                  << "2. Search a value" << std::endl
                  << "3. Delete a node" << std::endl
                  << "4. Count the number of nodes" << std::endl
                  << "5. Count the number of internal nodes" << std::endl
                  << "6. Count the number of nodes at a given level" << std::endl
                  << "7. Find the height of the tree" << std::endl
                  << "8. Check if the tree is balanced" << std::endl
                  << "9. Find parent" << std::endl
                  << "10. Find predecessor" << std::endl
                  << "11. Pre-order traversal" << std::endl
                  << "12. In-order traversal" << std::endl
                  << "13. Post-order traversal" << std::endl
                  << "14. Destroy the tree" << std::endl
                  << "15. Test all functions" << std::endl
                  << "0. Quit the system"  << std::endl;

        int input;
        std::cin >> input;
        std::string name;
        int age;
        while(input > 15 || input < 0) {
            //input validation
                std::cout << "Invalid input. Please enter a number between 0 and 15: " << std::endl;
                std::cin >> input;
        }

        switch (input) {
            case 1: {
                std::cout << "Enter name of pet:" << std::endl;
                std::cin >> name;
                std::cout << "Enter age of pet: " << std::endl;
                std::cin >> age;
                shelter.insertPet(name, age);
                break;
            }
            case 2: {
                std::cout << "Enter name to search: ";
                std::cin >> name;
                shelter.searchPet(name);
                break;
            }
            case 3: {
                std::cout << "Enter name to delete: ";
                std::cin >> name;
                shelter.deleteNodeDisplay(name);
                break;
            }
            case 4: {
                shelter.countNodesDisplay();
                break;
            }
            case 5: {
                shelter.countInternalNodesDisplay();
                break;
            }
            case 6: {
                std::cout << "Please enter the level to find: ";
                int level;
                std::cin >> level;
                shelter.countNodesAtLevelDisplay(level);
                break;
            }
            case 7: {
                shelter.findHeightDisplay();
                break;
            } 
            case 8: {
                shelter.isBalancedDisplay();
                break;
            }
            case 9: {
                std::cout << "Enter name of pet to find parent: " << std::endl;
                std::cin >> name;
                shelter.findParentDisplay(name);
                break;
            }
            case 10:{
                std::cout << "Enter the name of the pet whose predecessor you want to find: ";
                std::cin >> name;
                shelter.findPredecessorDisplay(name);
                break;
            }
            case 11: {
                std::cout << "Pre-order traversal: ";
                shelter.preorderDisplay();
                std::cout << std::endl;
                break;
            }
            case 12: {
                std::cout << "In-order traversal: ";
                shelter.inorderDisplay();
                std::cout << std::endl;
                break;
            }
            case 13: {
                std::cout << "Post-order traversal: ";
                shelter.postorderDisplay();
                std::cout << std::endl;
                break;
            }
        
            case 14: {
                shelter.destroyTreeDisplay();
                break;
            }

            case 15: {
                test(shelterTest);
                break;
            }
            case 0: {
                std::cout << "Bye!" << std::endl;
                return 0;
            }
        }
    }
    return 0;

}

void test(ShelterBST& tree) {
    std::cout << "Inserted 10 pets" << std::endl;
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
    tree.searchPet("Zelda");
    
    std::cout << std::endl;

    //unsuccesful search
    tree.searchPet("Jeff");
    
    std::cout << std::endl;

    //search parent
    std::cout << "Finding parent of 'Luna'" << std::endl;
    tree.findParentDisplay("Luna");
    std::cout << std::endl;

    //find predecessor
    std::cout << "Finding predecessor of 'Zelda'" << std::endl;
    tree.findPredecessorDisplay("Zelda");
    std::cout << std::endl;

    //count nodes
    std::cout << "Counting nodes..." << std::endl;
    tree.countNodesDisplay();
    std::cout << std::endl;

    //counting internal nodes
    std::cout << "Counting internal nodes..." << std::endl;
    tree.countIntNodesDisplay();
    std::cout << std::endl;

    //counting nodes at level 3
    std::cout << "Counting nodes at level 3..." << std::endl;
    tree.countHeightNodeDisplay(3);
    std::cout << std::endl;

    //find height
    std::cout << "Finding height of tree..." << std::endl;
    tree.findHeightDisplay();
    std::cout << std::endl;

    //check if balanced
    tree.isBalancedDisplay();
    std::cout << std::endl;

    //delete ryan
    std::cout << "Deleting 'Ryan'..." << std::endl;
    tree.deleteNodeDisplay("Ryan");
    std::cout << std::endl;

    //check display after deleting ryan
    std::cout << "Inorder Display after deleting 'Ryan':" << std::endl;
    tree.inorderDisplay();
    std::cout << std::endl;

    //destroy tree
    std::cout << "Destroying tree" << std::endl;
    tree.destroyTreeDisplay();
    std::cout << std::endl << std::endl;
}
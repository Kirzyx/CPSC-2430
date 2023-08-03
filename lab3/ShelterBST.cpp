#include <iostream>
#include <string>
#include "ShelterBST.h"

// Insert a pet into the binary search tree rooted at 'root'
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet) {
    if (root == nullptr) {
        root = new TreeNode;
        // Assign the pet to the new node
        root->pet = pet; 
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if (pet->age > root->pet->age) {
        // Recursively insert to the right subtree
        root->right = insert(root->right, pet); 
    }
    else if (pet->age < root->pet->age) {
        // Recursively insert to the left subtree
        root->left = insert(root->left, pet); 
    }
    return root;
}

// Search for a pet with the given age in the binary search tree rooted at 'root'
ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, int age) {
    if (root == nullptr || root->pet->age == age) {
        // Found or not found, return the current node
        return root; 
    }
    if (age > root->pet->age) {
        // Recursively search to the right subtree
        return search(root->right, age); 
    }
    else {
        // Recursively search to the left subtree
        return search(root->left, age); 
    }
}

// Traverse the binary search tree in order
void ShelterBST::inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // left middle right
    inorder(root->left);
    std::cout << root->pet->name << ":" << root->pet->age << std::endl;
    inorder(root->right);
}

// Traverse the binary search tree in preorder
void ShelterBST::preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    //middle left right
    std::cout << root->pet->name << ":" << root->pet->age << std::endl;
    preorder(root->left);
    preorder(root->right);
}

// Traverse the binary search tree in post order
void ShelterBST::postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    //left right middle
    postorder(root->left);
    postorder(root->right);
    std::cout << root->pet->name << ":" << root->pet->age << std::endl;
}

// Constructor for ShelterBST
ShelterBST::ShelterBST() {
    root = nullptr;
}

// Insert a new pet with the given name and age into the binary search tree
void ShelterBST::insertPet(std::string name, int age) {
    root = insert(root, new Pet(name, age));
}

// Search for a pet with the given age in the binary search tree
void ShelterBST::searchPet(int age) {
    TreeNode* result = search(root, age);
    if (result == nullptr) {
        std::cout << "No pet found of age " << age << std::endl;
    }
    else {
        std::cout << "The pet of age " << age << " is named " << result->pet->name << std::endl;
    }
}

void ShelterBST::inorderDisplay() {
    inorder(root);
}

void ShelterBST::preorderDisplay() {
    preorder(root);
}

void ShelterBST::postorderDisplay(){
    postorder(root);
}
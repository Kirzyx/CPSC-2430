#ifndef SHELTERBST_H
#define SHELTERBST_H

#include <string>

class ShelterBST {
private:
    struct Pet {
        std::string name;
        int age;
        Pet(std::string petName, int petAge) {
            name = petName;
            age = petAge;
        }
    };
    struct TreeNode {
        Pet* pet;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    TreeNode* insert(TreeNode * root, Pet* pet);
    TreeNode* search(TreeNode *root, int age);
    void inorder(TreeNode * root);
    void preorder(TreeNode * root);
    void postorder(TreeNode * root);

public:
    ShelterBST();
    void insertPet(std::string name, int age);
    void searchPet(int age);
    void inorderDisplay();
    void preorderDisplay();
    void postorderDisplay();
};

#endif /* SHELTERBST_H */
/* ShelterBST.h Class declarations */
#ifndef SHELTERBST_H
#define SHELTERBST_H
#include <iostream>
#include <string>
class ShelterBST {
    private:
        // Pet and TreeNode struct declaration
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
        // private function declarations (prototypes)
        TreeNode* insert(TreeNode* root, Pet* pet);
        TreeNode* search(TreeNode* root, std::string name);
        void inorder(TreeNode* root);
        void preorder(TreeNode* root);
        void postorder(TreeNode* root);
        TreeNode* findParent(TreeNode* root, std::string name);
        TreeNode* findPredecessor(TreeNode* root, std::string name);
        int countNodes(TreeNode* root);
        int countIntNodes(TreeNode* root);
        int countHeightNode(TreeNode* root, int level);
        int findHeight(TreeNode* root);
        bool balance(TreeNode* root);
        TreeNode* deleteNode(TreeNode* root, std::string name);
        TreeNode* destroy(TreeNode* root);
    public:
        ShelterBST();
        void insertPet(std::string name, int age);
        void searchPet(std::string name);
        void inorderDisplay();
        void preorderDisplay();
        void postorderDisplay();
        void test();
        void findParentDisplay(std::string name);
        void findPredecessorDisplay(std::string name);
        void countNodesDisplay();
        void countIntNodesDisplay();
        void countHeightNodeDisplay(int level);
        void findHeightDisplay();
        void isBalancedDisplay();
        void deleteNodeDisplay(std::string name);
        void destroyTreeDisplay();
};      
#endif
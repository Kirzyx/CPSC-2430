#include "ShelterBST.h"

/* SheterBST.cpp Class definitions */
ShelterBST::ShelterBST(){
    root = nullptr;
}
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet){
    if (root == nullptr) {
        root = new TreeNode;
        // Assign the pet to the new node
        root->pet = pet; 
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if (pet->name > root->pet->name) {
        // Recursively insert to the right subtree
        root->right = insert (root->right, pet); 
    }
    else if (pet->name < root->pet->name) {
        // Recursively insert to the left subtree
        root->left = insert (root->left, pet); 
    }
    return root;
}
    // define the rest of your private and Pet methods

    // Search for a pet with the given name in the binary search tree rooted at 'root'
ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, std::string name) {
    if (root == nullptr || (root->pet != nullptr && root->pet->name == name)) {
        // Found or not found, return the current node
        return root; 
    }
    if (name > root->pet->name) {
        // Recursively search to the right subtree
        return search(root->right, name); 
    }
    else {
        // Recursively search to the left subtree
        return search(root->left, name); 
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

ShelterBST::TreeNode* ShelterBST::findParent(TreeNode* root, std::string name) {
    if(root == nullptr) {
        return root;
    }
    if(root->left->pet->name == name || root->right->pet->name == name) {
        return root;
    }else{
        if (name > root->pet->name) {
            // Recursively search to the right subtree
            return findParent(root->right, name); 
        } else{
            // Recursively search to the left subtree
            return findParent(root->left, name); 
        }
    }
}

ShelterBST::TreeNode* ShelterBST::findPredecessor(TreeNode* root, std::string name){
    if (root == nullptr) {
        return root;
    }
    //search for node
    TreeNode* foundNode = search(root, name);
    if (foundNode == nullptr) {
        return nullptr;
    }
    //if left subtree of the chosen node is not empty
    if(foundNode->left != nullptr) {
        TreeNode* pred = foundNode->left;
        //find the rightmost node of the left subtree, which is the predcessor
        while(pred->right != nullptr) {
            pred = pred->right;
        }
        return pred;
    }
    return foundNode;
}


// Insert a new pet with the given name and age into the binary search tree
void ShelterBST::insertPet(std::string name, int age) {
    if(search(root, name) != nullptr) {
                    std::cout << "Error: " << name << " already exits" << std::endl;
    } else{
        root = insert(root, new Pet(name, age));
        std::cout << name << " was succesfully inserted" << std::endl;
    }
}

int ShelterBST::countNodes(TreeNode* root) {
    //base case
    if (root == nullptr) {
        return 0;
    }
    //recursively count the nodes in the left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);

}

int ShelterBST::countIntNodes(TreeNode* root) {
    //if tree is empty or if it has no children (being a leaf), return 0
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }
    //if root has atleast one child, recursively count the internal nodes in left and right subtrees
    return 1 + countIntNodes(root->left) + countIntNodes(root->right);
}

int ShelterBST::countHeightNode(TreeNode* root, int level) {
    //if tree is empty return 0
    if (root == nullptr) {
        return 0;
    }
    //if level is 0 return 1 for the root
    if (level == 0) {
        return 1;
    }
    //recursively count the nodes at the desired level in the left and right subtrees
    return countHeightNode(root->left, level - 1) + countHeightNode(root->right, level - 1);
}

int ShelterBST::findHeight(TreeNode* root) {
    //if tree is empty return -1
    if (root == nullptr) {
        return -1;
    }
    //recursively find the height of left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    //then return the maximum of the 2 heights
    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

bool ShelterBST::balance(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    //find height of left subtree and righ tsubtree
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    //check if heights differ by more than one, then return false if they do 
    if (leftHeight > rightHeight) {
        if (leftHeight - rightHeight > 1) {
            return false;
        }
    } else {
        if (rightHeight - leftHeight > 1) {
            return false;
        }
    }
    return balance(root->left) && balance(root->right);
}


ShelterBST::TreeNode* ShelterBST::deleteNode(TreeNode* root, std::string name) {
    if (root == nullptr) {
        return root;
    }
    //recursively search for the name to the left or right subtree
    else if (name < root->pet->name) {
        root->left = deleteNode(root->left, name);
    } 
    else if (name > root->pet->name) {
        root ->right = deleteNode(root->right, name);
    }
    //if pet's name is equal to the chosen name
    else {
        //if root has no children, delete it and set it to nullptr
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        //if root has one right child, replace it with the right child
        else if (root->left == nullptr) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        //if root has one left child, replace it with the left child
        else if (root->right == nullptr) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            //if root has 2 children, find predecessor
            TreeNode* temp = findPredecessor(root->left, name);
            //replace it with the predecessor node
            root->pet = temp->pet;
            //delete the predecessor
            root->left = deleteNode(root->left, temp->pet->name);
        }
    }
    return root;
}


ShelterBST::TreeNode* ShelterBST::destroy(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    //recursively delete left and right subtres
    destroy(root->left);
    destroy(root->right);
    //delete the root
    delete root;
    return nullptr;
}

void ShelterBST::findParentDisplay(std::string name) {
        TreeNode* parent = findParent(root, name);
        std::cout << "Parent of " << name  << " is " << parent->pet->name << ":" 
            << parent->pet->age << std::endl;
}

void ShelterBST::findPredecessorDisplay(std::string name) {
    TreeNode* predecessor = findPredecessor(root, name);
            if (predecessor == nullptr) {
                std::cout << "Pet not found or has no predecessor" << std::endl;
            } else {
                std::cout << "Predecessor of " << name << " is " << predecessor->pet->name << ":" 
                    << predecessor->pet->age << std::endl;
            }
}

void ShelterBST::countNodesDisplay() {
    std::cout << "There are " <<  countNodes(root) << " total nodes" << std::endl;
}

void ShelterBST::countIntNodesDisplay() {
    std::cout << "There are " << countIntNodes(root) << " internal nodes" << std::endl;
}

void ShelterBST::countHeightNodeDisplay(int level) {
    std::cout << "The number of nodes at level " << level << " is " << countHeightNode(root, level) << std::endl;
}

void ShelterBST::findHeightDisplay() {
    std::cout << "The height of the tree is " << findHeight(root) << std::endl;
}

void ShelterBST::isBalancedDisplay() {
    if (balance(root)) {
        std::cout << "The tree is balanced" << std::endl;
    } else {
        std::cout << "The tree is not balanced" << std::endl;
    }
}

void ShelterBST::deleteNodeDisplay(std::string name) {
    deleteNode(root, name);
    std::cout << name << " was succesfully deleted" << std::endl;
}


void ShelterBST::destroyTreeDisplay() {
    root = destroy(root);
    std::cout << "The tree was succesfully deleted" << std::endl;
}

// Search for a pet with the given age in the binary search tree
void ShelterBST::searchPet(std::string name) {
    TreeNode* result = search(root, name);
    if (result == nullptr) {
        std::cout << "No pet found of name " << name << std::endl;
    }
    else {
        std::cout << "The pet of name " << name << " is found" <<std::endl;
    }
}

void ShelterBST::inorderDisplay() {
    std::cout << std::endl;
    inorder(root);
}

void ShelterBST::preorderDisplay() {
    std::cout << std::endl;
    preorder(root);
}

void ShelterBST::postorderDisplay(){
    std::cout << std::endl;
    postorder(root);
}
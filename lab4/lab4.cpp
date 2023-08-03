//Ryan Luo
//Lab4

#include <iostream>
#include <vector>
#include <string>

struct Pet{
    std::string name;
    int arrival;
};
class PetHeap {
    private:
        std::vector<Pet*> petHeap;
        void percolateUp(int index);
        void percolateDown(int index);
        void deleteMin();
        Pet* peekMin();
    public:
        PetHeap(){
            petHeap = std::vector<Pet*>();
        }
        void insert(Pet* pet);
        Pet* adoptOldestPet();
        int numPets();
        void displayPets();
        ~PetHeap();
};


void test();

int main() {
    PetHeap shelter;

    std::string name;
    int arrival;
    int input;

    while(true){ 
        std::cout << "Welcome to Lab 4 on Basic Heap Operations. What would you like to test?" << std::endl;
            std::cout << "1. Insert Pet" << std::endl;
            std::cout << "2. Adopt Pet" << std::endl;
            std::cout << "3. Number of Pets" << std::endl;
            std::cout << "4. Display Pets" << std::endl;
            std::cout << "5. Run Tests" << std::endl;
            std::cout << "6. Exit" << std::endl;
            std::cin >> input;

            while(input < 1 || input > 6) {
                std::cout << "Input a value between 1 and 6: ";
                std::cin >> input;
            }
            
            switch (input) {
                case 1: {
                    std::cout << "Enter pet name: ";
                    std::cin >> name;
                    std::cout << "Enter arrival time: ";
                    std::cin >> arrival;
                    Pet* pet = new Pet{name, arrival};
                    shelter.insert(pet);
                    break;
                }
                case 2: {
                    Pet* pet = shelter.adoptOldestPet();
                    if (pet == nullptr) {
                        break;
                    }
                    std::cout << "Adopted " << pet->name << ", arrival " << pet->arrival << std::endl;
                    std::cout << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Number of pets: " << shelter.numPets() << std::endl;
                    std::cout << std::endl;
                    break;
                }
                case 4: {
                    std::cout << "Pets in the heap in level order:" << std::endl;
                    shelter.displayPets();
                    std::cout << std::endl;
                    break;
                }
                case 5: {
                    test();
                    break;
                }
                case 6: {
                    std::cout << "Goodbye!" << std::endl;
                    std::cout << std::endl;
                    return 0;
                    break;
                }
            
        }
    }
    return 0;
}   



void PetHeap::percolateUp(int index) {
    // Maintain heap structure from bottom to top
    
    // Base case
    if (index == 0) {
        return;
    }
    int parentIndex = (index - 1) / 2;
    if (petHeap[index]->arrival < petHeap[parentIndex]->arrival) {
        // Swap the elements
        Pet* temp = petHeap[index];
        petHeap[index] = petHeap[parentIndex];
        petHeap[parentIndex] = temp;
        // Recurse on the parent index
        percolateUp(parentIndex);
    }
}



void PetHeap::percolateDown(int index) {
    //maintain heap structure from top to bottom
        
    //base cases
    //if current node is a leaf node
    if (index >= (int)(petHeap.size())/2) {
        return;
    }
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    int smallerChild = leftChild;

    //check if node has two children
    if (rightChild < (int)(petHeap.size()) && petHeap[rightChild]->arrival < petHeap[leftChild]->arrival) {
        smallerChild = rightChild;
    }
    //if current node has only a left child and the value of the node is smaller than both children, we can stop
    if (petHeap[index]->arrival <= petHeap[smallerChild]->arrival) {
        return;
    }
    //swap the smaller node with current node
    Pet* temp = petHeap[index];
    petHeap[index] = petHeap[smallerChild];
    petHeap[smallerChild] = temp;
    //recursively call percolateDown with the swapped node
    percolateDown(smallerChild);
}


void PetHeap::deleteMin() {
    //remove the oldest Pet (by arrival from the heap)
    //reconstruct the heap after deletion

    petHeap[0] = petHeap.back();
    petHeap.pop_back();
    //add code here - calls percolateDown
    percolateDown(0);
    
}

Pet* PetHeap::peekMin() {
    //return oldest Pet (by arrival)
    //in the heap (dont delete it)
    if(petHeap.size() == 0) {
        return nullptr;
    }
    return petHeap[0];
}

void PetHeap::insert(Pet* pet) {
    //insert a pet into your min heap based on arrival
    petHeap.push_back(pet);
    percolateUp(petHeap.size() - 1);
}

Pet* PetHeap::adoptOldestPet() {
    if (petHeap.size() == 0) {
        std::cout << "No pets in shelter" << std::endl << std::endl;
        return nullptr;
    }
    //set adoptedPet to highest priority, delete from heap and return it
    Pet* adoptedPet = peekMin();
    deleteMin();
    return adoptedPet;
}

int PetHeap::numPets(){
    //return number of pets in the shelter (heap)
    return(petHeap.size());
}

void PetHeap::displayPets() {
    // display pets (name and arrival time) by level-order
    for(int i = 0; i < (int)(petHeap.size()); i++) {
        std::cout << petHeap[i]->name << " : " << petHeap[i]->arrival << std::endl;
    }
}   

PetHeap::~PetHeap() {
    //deallocate memory
    petHeap.clear();
}

void test() {
    PetHeap shelter;
    //insert 10 pets
    shelter.insert(new Pet{"Zelda", 5});
    shelter.insert(new Pet{"Link", 7});
    shelter.insert(new Pet{"Joe", 4});
    shelter.insert(new Pet{"Nathan", 3});
    shelter.insert(new Pet{"Ryan", 10});
    shelter.insert(new Pet{"Oreo", 2});
    shelter.insert(new Pet{"Luna", 6});
    shelter.insert(new Pet{"Charlie", 8});
    shelter.insert(new Pet{"Bella", 9});
    shelter.insert(new Pet{"Zeus", 1});
   
    //display
    std::cout << "Heap in level order: " << std::endl;
    shelter.displayPets();
   
    //adopt a few pets
    std::cout << std::endl << "Adopting pets" << std::endl;
    for (int i = 0; i < 3; i++) {
        Pet* pet = shelter.adoptOldestPet();
        std::cout << "Adopted " << pet->name << " : " << pet->arrival << std::endl;
    }
   
    std::cout << std::endl;
    //count pets after adoption
    std::cout << "Number of pets left" << std::endl;
    std::cout << shelter.numPets() << std::endl << std::endl;
    
    //display
    std::cout << "Heap in level order after adoption: " << std::endl;
    shelter.displayPets();
   
   std::cout << std::endl;

    //adopt rest of pets
    std::cout << "Adopt rest of the pets" << std::endl;
    while(shelter.numPets() > 0) {
        Pet* pet = shelter.adoptOldestPet();
        std::cout << "Adopted " << pet->name << " : " << pet->arrival << std::endl;
    }
    //check number of pets
    std::cout << std::endl << "Number of pets left" << std::endl;
    std::cout << shelter.numPets() << std::endl << std::endl;
    
    //attempt to adopt another pet
    std::cout << "Attempt to adopt pet" << std::endl;
    shelter.adoptOldestPet();
    
}


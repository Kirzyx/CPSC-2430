#include <iostream>
#include <queue>

struct Pet {
    std::string name;
    std::string type;
    int time; 
};

class Shelter  {
    private:
    std::queue<Pet> dogs;
    std::queue<Pet> cats;
    int arrival_time;
    
    public:
    // Constructor to set the arrival time to 0
    Shelter();
    
    // Add a dog to the shelter, by creating a new Pet and pushing it to the dogs queue
    void add_dog(std::string name);
    
    // Add a cat to the shelter, by creating a new Pet and pushing it to the cats queue
    void add_cat(std::string name);
    
    // Adopt a dog from the shelter by removing it from the dogs queue and returning it
    // Returns an empty Pet if the dogs queue is empty
    Pet adopt_dog();
    
    // Adopt a cat from the shelter by removing it from the cats queue and returning it
    // Returns an empty Pet if the cats queue is empty
    Pet adopt_cat();
    
    // Adopt any animal from the shelter by returning the animal with the smallest arrival time
    // If both queues are empty, returns an empty Pet
    Pet adopt_any();
};

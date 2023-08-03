//Ryan Luo
//Description: Program creates an animal shelter where the user can add animals to it then
//adopt them

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

int main() {
  std::cout << std::endl;

  int input;

  Shelter animal_shelter;

  while (true) {
    std::cout << std::endl << std::endl;
    //User interface
    std::cout << "Welcome to the animal shelter. What would you like to do?" << std::endl;
    std::cout << "1. Add a CAT to the shelter" << std::endl; 
    std::cout << "2. Add a DOG to the shelter" << std::endl;
    std::cout << "3. Adopt a CAT to the shelter" << std::endl;
    std::cout << "4. Adopt a DOG from the shelter" << std::endl;
    std::cout << "5. Adopt any animal from the shelter" << std::endl;
    std::cout << "6. Exit" << std::endl << std::endl;

    //get input
    std::cin >> input;
    //end program
    if (input == 6) {
      return 0;
    }
    //input to add cat
    switch (input) {
      case 1: {
        std::string cat_name;
        std::cout << "Please enter the CAT's name: ";
        std::cin >> cat_name;
        animal_shelter.add_cat(cat_name);
        break;
      }
      //input to add dog
      case 2: {
        std::string dog_name;
        std::cout << "Please enter the DOG's name: ";
        std::cin >> dog_name;
        animal_shelter.add_dog(dog_name);
        break;
      }
      //input to adopt cat
      case 3: {
        Pet cat = animal_shelter.adopt_cat();
        if(cat.name.empty()) {
          std::cout << "Sorry, no cat avaliable for adoption today";
          break;
        }
        std::cout << "Congrats on adopting a cat, their name is: " << cat.name;
        break;
      }
      //input to adopt dog
      case 4: {
        Pet dog = animal_shelter.adopt_dog();
        if(dog.name.empty()) {
          std::cout << "Sorry, no dogs avaliable for adoption today";
          break;
        }
        std::cout << "Congrats on adopting a dog their name is " << dog.name;
        break;
      }
      //input to adopt any animal
      case 5: {
        Pet animal = animal_shelter.adopt_any();
        if(animal.name.empty()) {
          std::cout << "Sorry, no animal avaliable for adoption today" << std::endl;
          break;
        }
        if (animal.type == "dog") {
          std::cout << "Congrats on adopting a dog their name is: " << animal.name;
        } else if (animal.type == "cat") {
          std::cout << "Congrats on adopting a cat their name is: " << animal.name;
        }
        break;
      }
    }
  }
  
  return 0;
}

Shelter::Shelter(){
    //Set arrival time to 0
    arrival_time = 0;
}

void Shelter::add_dog(std::string name) {
    Pet dog;
    //create dog and change the type to dog and change name to the user's input
    //set arrival time to incremented time
    dog.name = name;
    dog.type = "dog";
    dog.time = arrival_time++;
    dogs.push(dog);
}

void Shelter::add_cat(std::string name) {
    //create cat and change the type to cat and change name to the user's input
    //set arrival time to incremented time
    Pet cat;
    cat.name = name;
    cat.type = "cat";
    cat.time = arrival_time++;
    cats.push(cat);
}

Pet Shelter::adopt_dog(){
    //return nothing if dogs queue is empty
    if(dogs.empty()) {
        return Pet();
    }
    //Assign front dog to variable
    Pet dog = dogs.front();
    dogs.pop();
    return dog;
}

Pet Shelter::adopt_cat(){
    //return nothing if cats queue is empty
    if(cats.empty()) {
        return Pet();
    }
    //Assign front cat of the queue to variable
    Pet cat = cats.front();
    cats.pop();
    return cat;
}

Pet Shelter::adopt_any() {
    //Check if both queues are empty
    if(dogs.empty() && cats.empty()){
        return Pet();
    }
    //if dogs queue is empty adopt cat
    else if (dogs.empty()) {
        return adopt_cat();
    }
    //if cats queue is empty adopt dog
    else if(cats.empty()){
        return adopt_dog();
    }
    else {
        Pet dog = dogs.front();
        Pet cat = cats.front();
        //check arrival time to adopt dog or cat
        if(dog.time < cat.time) {
            return dog;
        }
        else{
            return cat;
        }
    }
    
}
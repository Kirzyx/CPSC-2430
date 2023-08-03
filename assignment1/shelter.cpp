#include "shelter.h"

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
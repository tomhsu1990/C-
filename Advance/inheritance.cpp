#include <stdio.h>
#include <vector>

enum Diet{
	Herbivore=0, Carnivore
};
char diet_type[2][10] = {"Herbivore", "Carnivore"};

class Animal{
public:
	Animal(){}
	virtual void eat()=0;
	Diet diet;
};

class Lion : public Animal {
public: 
	Lion(){
		this->diet = Carnivore;
	}
	void eat();
};
void Lion::eat() {
	fprintf(stderr, "Lion is %s\n", diet_type[diet]);
}

class Sheep : public Animal {
public:
	Sheep(){
		this->diet = Herbivore;
	}
	void eat();
};
void Sheep::eat() {
	fprintf(stderr, "Sheep is %s\n", diet_type[diet]);
}

class Zoo {
public:
	// std::vector<Animal> animals; // this is wrong because the type is not polymorphic to different animals
	std::vector<Animal*> animals;
	void addAnimals (Animal *animal) {
		animals.push_back(animal);
	}
	void feedAnimals () {
		for (int i=0;i<animals.size();++i) {
			animals[i]->eat();
		}
	}
};

int main () {
	Zoo zoo;
	Lion lion;
	Sheep sheep;
	zoo.addAnimals(&lion);
	zoo.addAnimals(&sheep);
	zoo.feedAnimals();
	return 0;
}
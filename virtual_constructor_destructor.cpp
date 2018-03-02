#include <iostream>
using namespace std;

class Cat{
public:
	Cat () {
		cout << "Cat is born." << endl;
		meow();
	}
	~Cat () {
		cout << "Cat ran away." << endl;
		meow();
	}
	
	virtual void meow () {
		cout << "MEOW! I am a cat." << endl;
	}
	// void meow () {
	// 	cout << "MEOW! I am a cat." << endl;
	// }

	void seeMouse () {
		meow();
	}
};

class Kitty : public Cat{
public:
	Kitty () {
		cout << "Kitty is born." << endl;
		meow();
	}
	~Kitty () {
		cout << "Kitty ran away." << endl;
		meow();
	}
	
	virtual void meow () {
		cout << "MEOW! I am a kitty cat." << endl;
	}
	// void meow () {
	// 	cout << "MEOW! I am a kitty cat." << endl;
	// }
};

int main (int argc, char* argv[]) {
	Kitty kitty;
	kitty.seeMouse();
	return 0;
}
// Since meow is virtual in Cat, when a kitty see a mouse,
// it is the exactly the kitty.
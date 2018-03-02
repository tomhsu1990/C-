#include <iostream>
using namespace std;

class Obstacle{
public:
	virtual Obstacle* clone () {
		return new Obstacle(*this);
	}
	virtual void name () {
		cout << "This is an obstacle prototype." << endl;
	}
};

class Segment : public Obstacle {
public:
	virtual Segment* clone () {
		return new Segment(*this);
	}
	virtual void name () {
		cout << "This is a segment obstacle." << endl;
	}
};

// Here, clone is like a virtual constructor.
// Although the type is cast into its parent type,
// it still outputs its name after a proper type construction.
void test (Obstacle* obst) {
	Obstacle *cln = obst->clone(); 
	cln->name();
}

int main (int argc, char* argv[]) {
	Segment seg;
	test(&seg);
	return 0;
}

#include <iostream>
using namespace std;

class Obstacle{
public:
	virtual ~Obstacle () {
		cout << "Delete Obstacle" << endl;
	}
	// with virtual
	// Delete Segment
	// Delete Obstacle
	
	// ~Obstacle () {
	// 	cout << "Delete Obstacle" << endl;
	// }
	// without virtual
	// Delete Obstacle
};

class Segment : public Obstacle{
public:
	~Segment () {
		cout << "Delete Segment" << endl;
	}
};

class ObstacleGenerator{
public:
	static Obstacle* createSegment () {
		return new Segment();
	}
};
 
int main (int argc, char* argv[]) {
	Obstacle* obst = ObstacleGenerator::createSegment();
	delete obst;
	return 0;
}

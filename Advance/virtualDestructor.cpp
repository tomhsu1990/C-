#include <iostream>
using namespace std;

class Obstacle{
public:
	// with virtual
	virtual ~Obstacle () {
		cout << "Delete Obstacle" << endl;
	}
	// Delete Segment
	// Delete Obstacle
	
	// without virtual
	// ~Obstacle () {
	// 	cout << "Delete Obstacle" << endl;
	// }
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

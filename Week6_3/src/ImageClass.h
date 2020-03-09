#include "ofMain.h"
#include "ofxBox2d.h"

class Shape{
public:
	Shape();
	Shape(int x, int y);
	~Shape();

	//void Shape::draw();


	void update();
	void draw();
	void walk();

	ofColor color;
	int startingX;
	int startingY;
    int cornerRadius;
	float size;
	float size2;
	float size3;
	float size4;


	float bgFade;

	float rotationZ;
	float rotateZ;
	float rotationY;
	float rotateY;
	float rotationX;
	float rotateX;

	ofxBox2d box2d;
	ofxBox2dCircle circle;

	vector <shared_ptr<ofxBox2dCircle>> circles;



    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;

	void setInitialCondition(float px, float py, float vx, float vy);

	void resetForce();
    void addForce(float x, float y);
    void addDampingForce();

    float damping;


};


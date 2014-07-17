#include <iostream>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct point {
	double x,y;
};

class line {
private:
	double epsilon, slope, intercept;
	bool bslope;
public:
	line(){}
	line(point p, point q) {
		epsilon = 0.0001;
		if(abs(p.x - q.x) > epsilon) {
			slope = (p.y - q.y) / (p.x - q.x);
			intercept = p.y - slope * p.x;
			bslope = true;
		}
		else {
			bslope = false;
			intercept = p.x;
		}
	}
	int hashcode() {
		int sl = (int)(slope * 1000);
		int in = (int)(intercept * 1000);
		return sl*1000 + in;
	}
	void print() {
		cout << "y = " << slope << "x + "<<intercept<<endl;
	}
};

line findBestLine(point *p, int pointNum) {
	line bestline;
	bool first = true;
	map<int, int> mii;
	for(int i = 0; i < pointNum; ++i) {
		for(int j = i+1; j < pointNum; ++j) {
			line l(p[i], p[j]);
			if(mii.find(l.hashcode()) == mii.end()) {
				mii[l.hashcode()] = 0;
			}
			mii[l.hashcode()] = mii[l.hashcode()] + 1;
			if(first) {
				bestline = l;
				first = false;
			}
			else {
				if(mii[l.hashcode()] > mii[bestline.hashcode()])
					bestline = l;
			}
		}
	}
}

int main() {
	srand((unsigned)time(0));
	int graph_size = 100;
	int pointNum = 50;
	point *p = new point[pointNum];
	for(int i = 0; i < pointNum; ++i) {
		p[i].x = rand()/double(RAND_MAX) * graph_size;
		p[i].y = rand()/double(RAND_MAX) * graph_size;
	}
	line l = findBestLine(p, pointNum);
	l.print();
	delete[] p;
	return 0;
}

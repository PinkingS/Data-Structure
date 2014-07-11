#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Animal {
	Animal(string s = "", bool t = 0): name(s), type(t) {}
	int order;
	string name;
	bool type; // 0:cat 1:dog
};

class animalQueue {
public:
	animalQueue() {
		order = 0;
	}

	void enqueue(Animal a) {
		a.order = order;
		if(a.type == 0)
			cats.push_back(a);
		else
			dogs.push_back(a);
		++order;
		cout << "enqueue " << a.name << " " << a.order << endl;
	}

	Animal dequeueAny() {
		Animal a;
		if(dogs.empty())
			return dequeueCat();
		else if(cats.empty())
			return dequeueDog();

		if(cats.front().order < dogs.front().order) {
			 a = cats.front();
			 cats.pop_front();
		} else {
			a = dogs.front();
			dogs.pop_front();
		}

		cout << "dequeue " << a.name << " " << a.order << endl;
		return a;
	}

	Animal dequeueCat() {
		Animal a;
		if(cats.empty()) {
			cout << "has no cats to dequeue !" << endl;
			return a; 
		}
		a = cats.front();
		cats.pop_front();
		cout << "dequeue " << a.name << " " << a.order << endl;
		return a;
	}

	Animal dequeueDog() {
		Animal a;
		if(dogs.empty()) {
			cout << "has no dogs to dequeue !" << endl;
			return a; 
		}
		a = dogs.front();
		dogs.pop_front();
		cout << "dequeue " << a.name << " " << a.order << endl;
		return a;
	}
private:
	list<Animal> cats, dogs;
	int order;
};

int main() {
	animalQueue q;
	q.enqueue(Animal("kitty", 0));
	q.dequeueDog();
	q.enqueue(Animal("doggy", 1));
	q.enqueue(Animal("kitty1", 0));
	q.enqueue(Animal("kitty2", 0));
	q.dequeueCat();
	q.dequeueAny();
	q.dequeueAny();
	q.dequeueAny();

	return 0;
}

// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


enum AnimalType{ CAT, DOG};

struct Record {
    string name;
    int time;
};

class Shelter {
    private:
        list<Record> cats;
        list<Record> dogs;
        int timer;
    public:
        Shelter() { timer = 0; }
        void enqueue(AnimalType type, string name) {
            Record r { name, timer++ };
            if (type == CAT) {
                cats.push_back(r);
            }
            else {
                dogs.push_back(r);
            }
        }
        string dequeueAny(){
            if (cats.empty()) { return dequeueDog();}
            if (dogs.empty()) { return dequeueCat();}
            int tDog = dogs.front().time;
            int tCat = cats.front().time;
            if (tCat < tDog) {
                return dequeueCat();
            }
            return dequeueDog();
        }

        string dequeueCat(){
            Record oldestCat = cats.front();
            cats.pop_front();
            return oldestCat.name;
        }

        string dequeueDog(){
            Record oldestDog = dogs.front();
            dogs.pop_front();
            return oldestDog.name;
        }
        int size() {
            return dogs.size() + cats.size();
        }
        bool empty() {return cats.empty() && dogs.empty(); }
        bool hasDog() { return !dogs.empty();}
        bool hasCat() { return !cats.empty();}
};

int main(int argc, char* argv[])
{
    // Read input
    Shelter shelter;
    shelter.enqueue(CAT, "c1");
    shelter.enqueue(DOG, "d1");
    shelter.enqueue(DOG, "d2");
    shelter.enqueue(DOG, "d3");
    shelter.enqueue(CAT, "c2");
    shelter.enqueue(CAT, "c3");
    shelter.enqueue(DOG, "d4");
    shelter.enqueue(CAT, "c4");
    shelter.enqueue(DOG, "d5");
    for (int i = 0; i < 4; i++) {
        cout << "oldest cat: " << shelter.dequeueCat() << '\n'; 
    }
    while (!shelter.empty()) {
        cout << "oldest animal: " << shelter.dequeueAny() << '\n';
    }
    return 0;
}

#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Station {
public:
    string name;
    float lengthToNext;
    int countOfPeple;

    Station(string n, float l) {
        name = n;
        lengthToNext = l;
        countOfPeple = (rand() % 800) + 1;
    }
};

class Line {
public:
    vector<Station> stantions;
};

class Train {
    const int vans = 10;
    const int capacityOfvan = 50;

    int tNow;
    int tGo;

    void PeopleMoving() {
        peopleInTrain += curSt.countOfPeple;
        if (peopleInTrain > capacity) {
            peopleInTrain = capacity;
            curSt.countOfPeple -= capacity;
        }
        else {
            curSt.countOfPeple = 0;
        }
        if (peopleInTrain > 0) {
            peopleInTrain -= (rand() % peopleInTrain) + 1;
        }
    }
public:
    Line way;
    const int capacity = vans * capacityOfvan;
    int peopleInTrain = 0;
    bool end;
    float maxVelocity = 70.0f;
    int numSt = 0;
    Station curSt = way.stantions[numSt];

    Train(Line w) : way(w) {}



    void Display() {
        cout << "came" << endl;
        cout << "current station: " << curSt.name << endl;
        cout << "current count of people in train: " << peopleInTrain << endl;
        cout << "current count of people on station: " << curSt.countOfPeple << endl;
    }

    

    void move() {
        PeopleMoving();
        Display();

        tGo = (curSt.lengthToNext / maxVelocity) * 3600;
        tNow = (int)time(0);
        tick();
    }

    void tick() {
        int tEnd = tNow + tGo;
        cout << "on way" << endl;
        while (true)
        {
            tNow = (int)time(0);
            if (tNow >= tEnd) {
                break;
            }
        }
        if (numSt == way.stantions.size() - 1)
        {
            end = true;
        }
        else
        {
            numSt++;
            curSt = way.stantions[numSt];
        }
    }

    void Start() {
        while (true)
        {
            if (!end)
            {
                move();
            }
            else
            {
                cout << "final stop" << endl;
                break;
            }
        }
    }
};


int main() {
    srand((int)time(0));
    //initialization

    Line zmsk;
    Station kl("kolomen", 0.1f);
    Station th("tehno", 0.1f);
    Station av("avtozavod", 0.1f);

    zmsk.stantions.push_back(kl);
    zmsk.stantions.push_back(th);
    zmsk.stantions.push_back(av);

    Train train(zmsk);
    train.Start();
}
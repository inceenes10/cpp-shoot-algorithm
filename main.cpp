#include <iostream>
#include <cstdlib>
#include <time.h>


int getAliveCount(bool arr[]) {
   
    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (arr[i]) {
            count += 1;
        }
    }

    return count;
}


int getIndex(bool targetAlives[], int currentIndex) {
    
    int index = -1;

    for (int i = currentIndex; i < currentIndex + 3; i++) {
        int j = (currentIndex + 1) % 3;
        if (targetAlives[j] == true) {
            index = j;
        }
    }

    return index;
}


void shoot(bool &targetAlive, double accuracy) {
    
    double randomNumber = ((double) rand() / (RAND_MAX));
    
    if (randomNumber < accuracy) {
        targetAlive = false;
    }

}

std::string startDuel() {
    srand(time(NULL));
    
    std::string names[] = {"Aaron", "Bob", "Charlie"};
    bool targetAlives[] = {true, true, true};
    double accuracies[] = {0.33, 0.5, 1};

    int i = 0;

    while (getAliveCount(targetAlives) != 1) {

        int j_index = getIndex(targetAlives, i);

        if (j_index != i && j_index != -1) {
            // shoot
            shoot(targetAlives[j_index], accuracies[i]);
        }

        if (i == 2)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }

    int k = 0;
    for (k = 0; k < 3; k++) {
        if (targetAlives[k] == true) {
            break;
        }
    }

    return names[i];
}

int main() {

    std::string name = startDuel();

    std::cout << name << std::endl;
}

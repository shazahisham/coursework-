#include <iostream>
using namespace std;


long long movesNeeded(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= 3;
    }
    return result - 1;
}

void moveDisks(int n, char from, char via, char to, long long &count) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << via << endl;
        cout << "Move disk 1 from " << via << " to " << to << endl;
        count += 2;
        return;
    }

    moveDisks(n - 1, from, via, to, count);     
    cout << "Move disk " << n << " from " << from << " to " << via << endl;
    count++;
    moveDisks(n - 1, to, via, from, count);      
    cout << "Move disk " << n << " from " << via << " to " << to << endl;
    count++;
    moveDisks(n - 1, from, via, to, count);     
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    long long count = 0;

    cout << "\nSteps:\n";
    moveDisks(n, 'A', 'B', 'C', count);

    cout << "\nTotal moves = " << count
         << " (Expected = " << movesNeeded(n) << ")\n";

    return 0;
}
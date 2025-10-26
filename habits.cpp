#include <iostream>
#include <vector>
using namespace std;

struct Habit {
    string name;
    int streak;
    int goal;
};

void addHabit(vector<Habit> &h) {
    Habit x;
    cout << "Enter habit name: ";
    cin.ignore();
    getline(cin, x.name);
    cout << "Enter goal in days: ";
    cin >> x.goal;
    x.streak = 0;
    h.push_back(x);
    cout << "Best of luck on Completing your Goal!\n";
}

void updateHabit(vector<Habit> &h) {
    string name;
    cout << "Enter habit name: ";
    cin.ignore();
    getline(cin, name);
    for (auto &x : h) {
        if (x.name == name) {
            x.streak++;
            cout << "Keep going! Your Streak is : " << x.streak << "/" << x.goal << "\n";
            if (x.streak == x.goal) cout << " Goal completed!\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}

void showHabits(const vector<Habit> &h) {
    if (h.empty()) { cout << "No habits yet.\n"; return; }
    cout << "\n--- Your Habits ---\n";
    for (auto &x : h)
        cout << x.name << " -> " << x.streak << "/" << x.goal << "\n";
}

int main() {
    vector<Habit> habits;
    int ch;
    while (true) {
        cout << "\n1.Add  2.Update  3.Show  4.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: addHabit(habits); break;
            case 2: updateHabit(habits); break;
            case 3: showHabits(habits); break;
            case 4: return 0;
            default: cout << "Invalid!\n";
        }
    }
}

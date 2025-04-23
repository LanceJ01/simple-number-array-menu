#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int> &v);
void handle_quit();
void handle_unknown();

void display_menu();
char get_selection();
double calculate_mean(const vector<int> &v);
bool find(const vector<int> &v, int target);

int main() {

    vector<int> numbers;
    char selection{};

    do {
        display_menu();
        selection = get_selection();
        switch (selection) {
        case 'P':
            handle_display(numbers);
            break;
        case 'A':
            handle_add(numbers);
            break;
        case 'M':
            handle_mean(numbers);
            break;
        case 'S':
            handle_smallest(numbers);
            break;
        case 'L':
            handle_largest(numbers);
            break;
        case 'F':
            handle_find(numbers);
            break;
        case 'Q':
            handle_quit();
            break;
        default:
            handle_unknown();
        }
    } while (selection != 'Q');

    cout << endl;
    return 0;
}

void display_menu() {
    cout << "\nP - Print Numbers" << "\n";
    cout << "A - Add a number" << "\n";
    cout << "M - Display mean numbers" << "\n";
    cout << "S - Display smallest number" << "\n";
    cout << "L - Display largest number" << "\n";
    cout << "F - Find a number" << "\n";
    cout << "Q - Quit" << "\n";
    cout << "\nEnter your choice:";
}

char get_selection() {
    char selection{};
    cin >> selection;
    return static_cast<char>(toupper(selection));
}

void display_list(const vector<int> &v) {
    cout << "[ ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

void handle_display(const vector<int> &v) {
    if (v.size() == 0)
        cout << "[] - the list is empty" << endl;
    else
        display_list(v);
}

void handle_add(vector<int> &v) {
    int num_to_add{};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    v.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

double calculate_mean(const vector<int> &v) {
    int total{};
    for (auto num : v) {
        total += num;
    }
    return static_cast<double>(total) / v.size();
}

void handle_mean(const vector<int> &v) {
    if (v.size() == 0) {
        cout << "Unable to calculate mean - list is empty" << endl;
    } else {
        cout << "The mean is: " << calculate_mean(v) << endl;
    }
}

void handle_smallest(const vector<int> &v) {
    if (v.empty()) {
        cout << "The list is empty" << endl;
    }

    int smallest = v[0];
    for (auto num : v) {
        if (num < smallest) {
            smallest = num;
        }
    }
    cout << "The smallest number is: " << smallest << endl;
}

void handle_largest(const vector<int> &v) {
    if (v.empty()) {
        cout << "The list is empty" << endl;
    }

    int largest = v[0];
    for (auto num : v) {
        if (num > largest) {
            largest = num;
        }
    }
    cout << "The largest number is: " << largest << endl;
}

bool find(const vector<int> &v, int target) {
    for (auto num : v) {
        if (num == target) {
            return true;
        }
    }
    return false;
}

void handle_find(const vector<int> &v) {
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;

    if (find(v, target)) {
        cout << target << " was found!" << "\n";
    } else {
        cout << target << " wasn't found" << endl;
    }
}

void handle_quit() { cout << "Goodbye" << endl; }

void handle_unknown() { cout << "Unknown selection - try again" << endl; }

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <shlobj.h>

using namespace std;

// Define the Course structure
struct Course {
    string courseId;
    string title;
    vector<string> prerequisites;
};

// Helper function to convert a string to uppercase for case-insensitive comparisons
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Helper function to trim whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// Get path to the executable's folder
string getExecutablePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    string fullPath(buffer);
    size_t pos = fullPath.find_last_of("/\\");
    return (pos == string::npos) ? "" : fullPath.substr(0, pos + 1);
}

// Load courses from the file into the map
void loadCourses(const string& filename, map<string, Course>& courses) {
    string fullPath = getExecutablePath() + filename;
    ifstream file(fullPath);

    ofstream log("file_load_log.txt", ios::app);
    log << "Attempting to open: " << fullPath << endl;

    if (!file.is_open()) {
        log << "Failed to open file at: " << fullPath << endl;
        cout << "Could not open file at default location. Please enter full path: ";
        string manualPath;
        getline(cin, manualPath);
        file.open(manualPath);
        log << "Manual path attempt: " << manualPath << (file.is_open() ? " [SUCCESS]" : " [FAILED]") << endl;

        if (!file.is_open()) {
            cout << "Error: Could not open file." << endl;
            log << "Final status: Failed to load any file." << endl;
            log.close();
            return;
        }
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string courseId, title, prereq;
        getline(iss, courseId, ',');
        getline(iss, title, ',');

        Course course;
        course.courseId = trim(courseId);
        course.title = trim(title);

        while (getline(iss, prereq, ',')) {
            course.prerequisites.push_back(trim(prereq));
        }

        courses[toUpper(course.courseId)] = course;
    }

    log << "File loaded successfully." << endl;
    log.close();
}

// Print all courses in alphanumeric order
void printCourseList(const map<string, Course>& courses) {
    cout << "\nHere is a sample schedule:\n\n";
    for (const auto& pair : courses) {
        cout << pair.second.courseId << ", " << pair.second.title << endl;
    }
    cout << endl;
}

// Print a single course and its prerequisites
void printCourseDetails(const map<string, Course>& courses, const string& courseId) {
    string id = toUpper(courseId);
    auto it = courses.find(id);
    if (it != courses.end()) {
        const Course& course = it->second;
        cout << course.courseId << ", " << course.title << endl;
        cout << "Prerequisites: ";
        if (course.prerequisites.empty()) {
            cout << "None";
        }
        else {
            for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                cout << course.prerequisites[i];
                if (i < course.prerequisites.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Course not found. Please check the course ID and try again." << endl;
    }
}

// Forward declarations
void printCourseList(const map<string, Course>& courses);
void printCourseDetails(const map<string, Course>& courses, const string& courseId);

int main() {
    map<string, Course> courses;
    string input;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (true) {
        cout << "\n  1. Load Data Structure." << endl;
        cout << "  2. Print Course List." << endl;
        cout << "  3. Print Course." << endl;
        cout << "  9. Exit" << endl;
        cout << "\nWhat would you like to do? ";

        string choiceInput;
        getline(cin, choiceInput);
        try {
            choice = stoi(choiceInput);
        }
        catch (...) {
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Automatically attempting to load 'CS 300 ABCU_Advising_Program_Input.csv'. Press Enter to continue or type a different file name: ";
            getline(cin, input);
            if (trim(input).empty()) {
                input = "CS 300 ABCU_Advising_Program_Input.csv";
            }
            loadCourses(input, courses);
            break;
        case 2:
            if (courses.empty()) {
                cout << "Please load data first." << endl;
            }
            else {
                printCourseList(courses);
            }
            break;
        case 3:
            if (courses.empty()) {
                cout << "Please load data first." << endl;
            }
            else {
                cout << "What course do you want to know about? (e.g., CSCI300)\n";
                cout << "\nEdge Case Tip:\n";
                cout << "The search is case-insensitive, but the course must exist in the dataset.\n";
                cout << "Try both valid and invalid course IDs to test the results.\n\n";
                cout << "Enter course ID: ";
                getline(cin, input);
                printCourseDetails(courses, input);
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;
        default:
            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}

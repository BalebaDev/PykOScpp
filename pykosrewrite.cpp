#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void editFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        string content;
        cout << "Enter the content to append to the file (press Ctrl+Z followed by Enter to finish):" << endl;
        while (getline(cin, content)) {
            file << content << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void deleteFile(const string& filename) {
    if (remove(filename.c_str()) != 0) {
        cout << "Unable to delete file: " << filename << endl;
    } else {
        cout << "File deleted successfully: " << filename << endl;
    }
}

void showFileProperties(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file.seekg(0, ios::end);
        int fileSize = file.tellg();
        cout << "File size: " << fileSize << " bytes" << endl;
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Open file" << endl;
    cout << "2. Edit file" << endl;
    cout << "3. Delete file" << endl;
    cout << "4. Show file properties" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            openFile(filename);
            break;
        case 2:
            editFile(filename);
            break;
        case 3:
            deleteFile(filename);
            break;
        case 4:
            showFileProperties(filename);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}

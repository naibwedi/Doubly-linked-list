#include <iostream>
#include <string>

using namespace std;

// Node class representing a single song in the playlist
class Node {
public:
    int songID;
    string title;
    string artist;
    Node* next;
    Node* prev;

    // Constructor to initialize a new Node
    Node(int songID, const string& title, const string& artist) {
        this->songID = songID;
        this->title = title;
        this->artist = artist;
        next = nullptr;
        prev = nullptr;
    }
};

// Playlist class managing the doubly linked list
class Playlist {
private:
    Node* head;  // Pointer to the head
    Node* tail;  // Pointer to the tail

public:
    // Constructor to initialize an empty playlist
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to clean up memory
    ~Playlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Method to add a new song to the playlist
    void addSong(int songID, const string& title, const string& artist) {
        Node* newNode = new Node(songID, title, artist);
        if (head != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    // Method to display all songs in the playlist in order
    void displayPlaylist() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->songID << ", Title: " << current->title
                 << ", Artist: " << current->artist << endl;
            current = current->next;
        }
    }

    // Method to display all songs in reverse order
    void displayPlaylistInReverse() const {
        Node* current = tail;
        while (current != nullptr) {
            cout << "ID: " << current->songID << ", Title: " << current->title
                 << ", Artist: " << current->artist << endl;
            current = current->prev;
        }
    }

    // Method to remove a song from the playlist by ID
    void removeSong(int songID) {
        Node* current = head;

        // Traverse the list to find the node with the given ID
        while (current != nullptr && current->songID != songID) {
            current = current->next;
        }

        // If the song is not found
        if (current == nullptr) {
            cout << "Song with ID " << songID << " not found in the playlist." << endl;
            return;
        }

        // Update pointers if the song is not the head
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            // If the song is the head, update the head pointer
            head = current->next;
        }

        // Update pointers if the song is not the tail
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            // If the song is the tail, update the tail pointer
            tail = current->prev;
        }

        // Delete the current node
        delete current;
        cout << "Song with ID " << songID << " has been deleted from the playlist." << endl;
    }

    // bool funciton to search for a song by ID
    bool searchSongByID(int songID) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->songID == songID) {
                cout << "Song found: ID: " << temp->songID << ", Title: " << temp->title
                     << ", Artist: " << temp->artist << endl;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

// Main function providing a menu-driven interface for the Playlist Management System
int main() {
    Playlist myPlaylist;
    int songID;
    string title;
    string artist;
    int choice;

    do {
        cout << "============================================\n";
        cout << "[1] -------- Add a new song ---------------]\n";
        cout << "[2] -------- Remove a song by ID ----------]\n";
        cout << "[3] -------- Display Playlist -------------]\n";
        cout << "[4] -------- Display in Reverse order -----]\n";
        cout << "[5] -------- Search a song by ID ----------]\n";
        cout << "[6] -------- Exit Program -----------------]\n";
        cout << "============================================\n";

        cout << "Input your choice (numeric only): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input song ID and check for duplicates
                do {
                    cout << "Enter a unique Song ID: ";
                    cin >> songID;
                    if (myPlaylist.searchSongByID(songID)) {
                        cout << "ID is already registered, please enter a different ID." << endl;
                    }
                } while (myPlaylist.searchSongByID(songID));

                // Input song details
                cout << "Enter song title: ";
                cin >> title;
                cout << "Enter artist name: ";
                cin >> artist;

                // Add the song to the playlist
                myPlaylist.addSong(songID, title, artist);
                break;

            case 2:
                // Remove a song by ID
                cout << "Enter the Song ID to remove: ";
                cin >> songID;
                myPlaylist.removeSong(songID);
                break;

            case 3:
                // Display the playlist
                cout << "Displaying Playlist: \n";
                myPlaylist.displayPlaylist();
                break;

            case 4:
                // Display the playlist in reverse order
                cout << "Displaying Playlist in Reverse Order: \n";
                myPlaylist.displayPlaylistInReverse();
                break;

            case 5:
                // Search for a song by ID
                cout << "Enter the Song ID to search for: ";
                cin >> songID;
                if (!myPlaylist.searchSongByID(songID)) {
                    cout << "Song with ID " << songID << " not found." << endl;
                }
                break;

            case 6:
                // Exit the program
                cout << "Exiting Program..." << endl;
                break;

            default:
                // Handle invalid choices
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

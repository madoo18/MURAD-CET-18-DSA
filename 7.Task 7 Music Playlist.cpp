#include <iostream>
#include <string>
using namespace std;

struct CSNode {
    int id;
    string title;
    string artist;
    float duration;
    CSNode* next;
};

struct CDNode {
    int id;
    string title;
    string artist;
    string album;
    float duration;
    CDNode* next;
    CDNode* prev;
};

CSNode* csHead = nullptr;
CDNode* cdHead = nullptr;
CDNode* currentTrack = nullptr;

CSNode* createCSNode(int id, string title, string artist, float duration) {
    CSNode* node = new CSNode{id, title, artist, duration, nullptr};
    return node;
}

void csInsertBeginning(int id, string title, string artist, float duration) {
    CSNode* node = createCSNode(id, title, artist, duration);
    if (!csHead) {
        csHead = node;
        node->next = node;
    } else {
        CSNode* temp = csHead;
        while (temp->next != csHead) temp = temp->next;
        node->next = csHead;
        temp->next = node;
        csHead = node;
    }
    cout << "Inserted\n";
}

void csInsertEnd(int id, string title, string artist, float duration) {
    CSNode* node = createCSNode(id, title, artist, duration);
    if (!csHead) {
        csHead = node;
        node->next = node;
    } else {
        CSNode* temp = csHead;
        while (temp->next != csHead) temp = temp->next;
        temp->next = node;
        node->next = csHead;
    }
    cout << "Inserted\n";
}

void csDeleteBeginning() {
    if (!csHead) { cout << "Empty\n"; return; }
    if (csHead->next == csHead) { delete csHead; csHead = nullptr; cout << "Deleted\n"; return; }
    CSNode* last = csHead;
    while (last->next != csHead) last = last->next;
    CSNode* del = csHead;
    csHead = csHead->next;
    last->next = csHead;
    delete del;
    cout << "Deleted\n";
}

void csDeleteEnd() {
    if (!csHead) { cout << "Empty\n"; return; }
    if (csHead->next == csHead) { delete csHead; csHead = nullptr; cout << "Deleted\n"; return; }
    CSNode* temp = csHead;
    while (temp->next->next != csHead) temp = temp->next;
    delete temp->next;
    temp->next = csHead;
    cout << "Deleted\n";
}

void csDeleteByID(int id) {
    if (!csHead) { cout << "Empty\n"; return; }
    if (csHead->id == id) { csDeleteBeginning(); return; }
    CSNode* temp = csHead;
    while (temp->next != csHead && temp->next->id != id) temp = temp->next;
    if (temp->next == csHead) { cout << "Not Found\n"; return; }
    CSNode* del = temp->next;
    temp->next = del->next;
    delete del;
    cout << "Deleted\n";
}

void csDisplay() {
    if (!csHead) { cout << "Empty\n"; return; }
    CSNode* temp = csHead;
    do {
        cout << temp->id << " " << temp->title << " " << temp->artist << " " << temp->duration << endl;
        temp = temp->next;
    } while (temp != csHead);
}

// ---------------- CDLL Functions ----------------

CDNode* createCDNode(int id, string title, string artist, string album, float duration) {
    return new CDNode{id, title, artist, album, duration, nullptr, nullptr};
}

void cdInsertBeginning(int id, string title, string artist, string album, float duration) {
    CDNode* node = createCDNode(id, title, artist, album, duration);
    if (!cdHead) {
        cdHead = node;
        node->next = node->prev = node;
        currentTrack = node;
    } else {
        CDNode* last = cdHead->prev;
        node->next = cdHead;
        node->prev = last;
        last->next = node;
        cdHead->prev = node;
        cdHead = node;
    }
    cout << "Inserted\n";
}

void cdInsertEnd(int id, string title, string artist, string album, float duration) {
    CDNode* node = createCDNode(id, title, artist, album, duration);
    if (!cdHead) { cdInsertBeginning(id, title, artist, album, duration); return; }
    CDNode* last = cdHead->prev;
    last->next = node;
    node->prev = last;
    node->next = cdHead;
    cdHead->prev = node;
    cout << "Inserted\n";
}

void cdDeleteBeginning() {
    if (!cdHead) { cout << "Empty\n"; return; }
    if (cdHead->next == cdHead) { delete cdHead; cdHead = currentTrack = nullptr; cout << "Deleted\n"; return; }
    CDNode* last = cdHead->prev;
    CDNode* del = cdHead;
    cdHead = cdHead->next;
    cdHead->prev = last;
    last->next = cdHead;
    if (currentTrack == del) currentTrack = cdHead;
    delete del;
    cout << "Deleted\n";
}

void cdDeleteEnd() {
    if (!cdHead) { cout << "Empty\n"; return; }
    if (cdHead->next == cdHead) { cdDeleteBeginning(); return; }
    CDNode* last = cdHead->prev;
    CDNode* secondLast = last->prev;
    secondLast->next = cdHead;
    cdHead->prev = secondLast;
    if (currentTrack == last) currentTrack = cdHead;
    delete last;
    cout << "Deleted\n";
}

void cdDisplayForward() {
    if (!cdHead) { cout << "Empty\n"; return; }
    CDNode* temp = cdHead;
    do {
        cout << temp->id << " " << temp->title << " " << temp->artist << " " << temp->album << " " << temp->duration << endl;
        temp = temp->next;
    } while (temp != cdHead);
}

void cdDisplayBackward() {
    if (!cdHead) { cout << "Empty\n"; return; }
    CDNode* temp = cdHead->prev;
    do {
        cout << temp->id << " " << temp->title << " " << temp->artist << " " << temp->album << " " << temp->duration << endl;
        temp = temp->prev;
    } while (temp != cdHead->prev);
}

void playNext() { if (currentTrack) { currentTrack = currentTrack->next; cout << "Now Playing: " << currentTrack->title << endl; } else cout << "Empty\n"; }
void playPrevious() { if (currentTrack) { currentTrack = currentTrack->prev; cout << "Now Playing: " << currentTrack->title << endl; } else cout << "Empty\n"; }

// ---------------- Main Menu ----------------

int main() {
    int type;
    cout << "1. Circular Singly Playlist\n2. Circular Doubly Playlist\nEnter Type: ";
    cin >> type;

    int choice;
    if (type == 1) {
        do {
            cout << "1 Insert Beginning\n2 Insert End\n3 Delete Beginning\n4 Delete End\n5 Delete by ID\n6 Display\n7 Exit\n>";
            cin >> choice;
            int id; string title, artist; float duration;

            if (choice == 1) { cout << "Enter ID: "; cin >> id; cout << "Title: "; cin >> title; cout << "Artist: "; cin >> artist; cout << "Duration: "; cin >> duration; csInsertBeginning(id,title,artist,duration); }
            else if (choice == 2) { cout << "Enter ID: "; cin >> id; cout << "Title: "; cin >> title; cout << "Artist: "; cin >> artist; cout << "Duration: "; cin >> duration; csInsertEnd(id,title,artist,duration); }
            else if (choice == 3) csDeleteBeginning();
            else if (choice == 4) csDeleteEnd();
            else if (choice == 5) { cout << "Enter ID to delete: "; cin >> id; csDeleteByID(id); }
            else if (choice == 6) csDisplay();
        } while (choice != 7);
    } else if (type == 2) {
        do {
            cout << "1 Insert Beginning\n2 Insert End\n3 Delete Beginning\n4 Delete End\n5 Display Forward\n6 Display Backward\n7 Next Track\n8 Previous Track\n9 Exit\n>";
            cin >> choice;
            int id; string title, artist, album; float duration;

            if (choice == 1) { cout << "ID: "; cin >> id; cout << "Title: "; cin >> title; cout << "Artist: "; cin >> artist; cout << "Album: "; cin >> album; cout << "Duration: "; cin >> duration; cdInsertBeginning(id,title,artist,album,duration); }
            else if (choice == 2) { cout << "ID: "; cin >> id; cout << "Title: "; cin >> title; cout << "Artist: "; cin >> artist; cout << "Album: "; cin >> album; cout << "Duration: "; cin >> duration; cdInsertEnd(id,title,artist,album,duration); }
            else if (choice == 3) cdDeleteBeginning();
            else if (choice == 4) cdDeleteEnd();
            else if (choice == 5) cdDisplayForward();
            else if (choice == 6) cdDisplayBackward();
            else if (choice == 7) playNext();
            else if (choice == 8) playPrevious();
        } while (choice != 9);
    }

    return 0;
}

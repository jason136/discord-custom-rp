#include "file.h"

using namespace std;

    //const char* clientID;
    //const char* state;
    //const char* details;
    //int64_t startTimestamp;
    //int64_t endTimestamp;
    //const char* largeImageKey;
    //const char* largeImageText;
    //const char* smallImageKey;
    //const char* smallImageText;
    //const char* partyID;
    //int partySize;
    //int partyMax;

std::list<std::string> GetFile() {
    char filename[] = "config.txt";
    ifstream file(filename);
    std::list<std::string> data;

    if (!file) {
        ofstream file(filename);
        for (int x = 0; x < 12; x++) {
            file << "0\n";
        }
        file.close();
    }
    else {
        string text;
        while (getline(file, text)) {
            data.push_back(text);
        }
        file.close();
    }
    return data;
}
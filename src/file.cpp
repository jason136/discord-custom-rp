#include <iostream>
#include <fstream>

#include "file.h"
#include "main.h"

using namespace std;

char filename[] = "config.txt";
discord_fields values;

struct discord_fields GetFile() {
    FILE *file;
    file = fopen(filename, "r");

    if (!file) {
        values = { "", "", "", 0, 0, "", "", "", "", "", 0, 0 };
        WriteFile();
    }
    else {
        //struct discord_fields* values = (struct discord_fields*)malloc(sizeof(struct discord_fields));
        ReadFile();
    }
    return values;
}

void WriteFile() {
    ofstream file(filename);
    file << values.clientID << "\n";
    file << values.state << "\n";
    file << values.details << "\n";
    file << values.startTimestamp << "\n";
    file << values.endTimestamp << "\n";
    file << values.largeImageKey << "\n";
    file << values.largeImageText << "\n";
    file << values.smallImageKey << "\n";
    file << values.smallImageText << "\n";
    file << values.partyID << "\n";
    file << values.partySize << "\n";
    file << values.partyMax << "\n";
    file.close();
}

void ReadFile() {
    string text;
    ifstream file(filename);
    int temp = 0;
    while (getline(file, text)) {
        temp += 1;
        switch (temp) {
        case 1:
            values.clientID = text;
            break;
        case 2:
            values.state = text;
            break;
        case 3:
            values.details = text;
            break;
        case 4:
            values.startTimestamp = stoll(text);
            break;
        case 5:
            values.endTimestamp = stoll(text);
            break;
        case 6:
            values.largeImageKey = text;
            break;
        case 7:
            values.largeImageText = text;
            break;
        case 8:
            values.smallImageKey = text;
            break;
        case 9:
            values.smallImageText = text;
            break;
        case 10:
            values.partyID = text;
            break;
        case 11:
            values.partySize = stol(text);
            break;
        case 12:
            values.partyMax = stol(text);
            break;
        }
    }
    file.close();
}
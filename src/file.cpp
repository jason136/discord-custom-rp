#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "file.h"

using namespace std;

char filename[] = "config.txt";
discord_fields values = { "a", "a", "a", 1, 1111111, "a", "a", "a", "a", "a", 1, 5 };

void GetFile() {
    FILE *file;
    file = fopen(filename, "r");

    if (!file) {
        file = fopen(filename, "w");
        fwrite(&values, sizeof(struct discord_fields), 1, file);
        fclose(file);
    }
    else {
        struct discord_fields data;
        while (fread(&data, sizeof(struct discord_fields), 1, file))
        fclose(file);
        values = data;
    }
}

void RefreshFile() {
    FILE *file;
    file = fopen(filename, "w");
    fwrite(&values, sizeof(struct discord_fields), 1, file);
    fclose(file);
    file = fopen(filename, "r");
    while (fread(&values, sizeof(struct discord_fields), 1, file))
    fclose(file);
}
#include "sea.h"
#include "compareSeaByName.h"



bool CompareSeaByName(const Sea& a, const Sea& b) {
    string nameA = a.name.substr(1, a.name.length() - 2);
    string nameB = b.name.substr(1, b.name.length() - 2);

    const string kRussianAlphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

    char firstA = toupper(nameA[0]);
    char firstB = toupper(nameB[0]);

    size_t posA = kRussianAlphabet.find(firstA);
    size_t posB = kRussianAlphabet.find(firstB);

    if (posA != string::npos && posB != string::npos) {
        return posA < posB;
    }

    return nameA < nameB;
}
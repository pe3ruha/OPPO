#include "sea.h"
#include "compareSeaByName.h"



bool compareSeaByName(const sea& a, const sea& b) {
    // —оздаем строки без кавычек дл€ сравнени€
    string A = a.name.substr(1, a.name.length() - 2);
    string B = b.name.substr(1, b.name.length() - 2);

    // –усский алфавит в правильном пор€дке
    string russianAlphabet = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";


    // —равниваем по первому символу
    char FA = toupper(A[0]);
    char FB = toupper(B[0]);

    // Ќаходим позиции в русском алфавите
    size_t posA = russianAlphabet.find(FA);
    size_t posB = russianAlphabet.find(FB);

    // ≈сли оба символа русские, сравниваем по позиции в алфавите
    if (posA != string::npos && posB != string::npos) {
        return posA < posB;
    }

    // ≈сли один из символов не русский, используем обычное сравнение
    return A < B;
}
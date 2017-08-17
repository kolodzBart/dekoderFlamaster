#include <iostream>
#include <cstdlib>

std::string rozwijanieWyrazow(const std::string &wyrazRozwijany) {
    int dlugosc = wyrazRozwijany.length();
    std::string iloscWystapien;
    std::string rozwiniety;
    char powtarzajacySieZnak;

    for (int i = 0; i < dlugosc; i++) {
        bool toLitera = wyrazRozwijany[i] >= 'A' && wyrazRozwijany[i] <= 'Z';
        if (toLitera) {
            powtarzajacySieZnak = wyrazRozwijany[i];
            iloscWystapien.clear();
            rozwiniety.append(1, powtarzajacySieZnak);
        }
        else {
            iloscWystapien += wyrazRozwijany[i];
            bool toOstatniZnak = i + 1 >= dlugosc;
            bool nastepnyToLitera = wyrazRozwijany[i + 1] >= 'A' && wyrazRozwijany[i + 1] <= 'Z';
            if (toOstatniZnak || nastepnyToLitera)
                rozwiniety.append(std::atoi(iloscWystapien.c_str()) - 1, powtarzajacySieZnak);
        }
    }

    return rozwiniety;
}

int main()
{
    std::string wyraz;
    int iloscTestow;
    std::cin >> iloscTestow;
    for (int i = 0; i < iloscTestow; i++) {
        std::cin >> wyraz;
        std::cout << rozwijanieWyrazow(wyraz) << std::endl;
    }

    return 0;
}

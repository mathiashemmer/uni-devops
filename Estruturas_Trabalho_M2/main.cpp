#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>

using namespace std;

string GenerateName()
{
    srand(time(NULL));
    string syllables[] = {"ba", "be", "bi", "bo", "bu", "ca", "ce", "ci", "co", "cu", "da", "de", "di", "do", "du",
                        "fa", "fe", "fi", "fo", "fu", "ga", "ge", "gi", "go", "gu", "ja", "je", "ji", "jo", "ju",
                        "la", "le", "li", "lo", "lu", "ma", "me", "mi", "mo", "mu", "na", "ne", "ni", "no", "nu",
                        "pa", "pe", "pi", "po", "pu", "ra", "re", "ri", "ro", "ru", "sa", "se", "si", "so", "su",
                        "ta", "te", "ti", "to", "tu", "va", "ve", "vi", "vo", "vu", "xa", "xe", "xi", "xo", "xu",
                        "za", "ze", "zi", "zo", "zu"};
    int numOfSyllables = (rand() % 4) + 2;
    string name = "";
    for(int i = 0; i < numOfSyllables; i++)
    {
        name = name + syllables[rand() % 79];
    }

    name[0] = toupper(name[0]);
    return name;
}

int main()
{

}

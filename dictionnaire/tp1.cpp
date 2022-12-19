// tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
bool cmp(const string lhs, const string rhs) {
    return lhs.length() < rhs.length();
}
// fonction pour elimine les espaces blanc
string TrimFunction(string str)
{
    const char* typeOfWhitespaces = " tnrfv";
    str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
    str.erase(0, str.find_first_not_of(typeOfWhitespaces));
    return str;
}
int main()
{
  
    vector<string>list;
  // fichier a recupurer 
    ifstream fout("sample.txt");
    
    
    //map a dtocker
    map<string, string> p1;

    string line,name,def;

    int max = 0;
    
    while (fout)
    {
        // recupurer la taille de la line
        max = line.length();
        name = " ";
        def = " ";
        // recupurer la line 
        getline(fout, line);
        // return l'index de :
        int end = line.find(':');
        // recupurer le nom 
        name = TrimFunction(line.substr(0, end));
        // recupurer la definition
        def = line.substr(end+1, max);
        // inserer l'objet 
        p1.insert({ name,def });
    }
    fout.close();
    
    cout << "-------------------------" << endl;

    cout << " Donner le mot que vous voulez cherchez  " << endl;
    cin >> name;

    cout << "-------------------------" << endl;
    //utiliser binary search pour rechercher sur le mot binary search est deja implimenté dans la fonction find 
    auto search= p1.find(name);
    // si deja existe return le nom + definition 
    if (search != p1.end())
        std::cout << "Found " << search->first << " " << search->second << '\n';
    else
        std::cout << "Not found\n";
    
    cout << "----------" << endl;

   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

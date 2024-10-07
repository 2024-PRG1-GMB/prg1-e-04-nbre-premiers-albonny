#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    const int prime_lower_bound = 2;
    const int prime_upper_bound = 1000;
    const int largest_prime_factor = 31;
    const int new_line_choice = 5; //pour ne pas coder en dur les nombres qui sont utiles pour l'alorithme de détection des nombres premiers

    SetConsoleOutputCP(CP_UTF8); //Cette méthode sert à faire en sorte de pouvoir utiliser des accents dans la console

    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
         << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "Bonjour! Ce programme sert à afficher tous les nombres premiers jusqu'à la valeur que écrirez!";


    string restart_program;

    do {
        cout << endl << endl;

        double user_upper_bound;
        do {
            cout << "Entrez une valeur [2-1000] :";
            cin >> user_upper_bound;
        } while (user_upper_bound < prime_lower_bound || user_upper_bound > prime_upper_bound); //Nécessaire pour que notre entrée soit entre 2 et 1000

        cout << endl << "Voici la liste des nombres premiers : " << endl;


        int new_line = 0;

        for (int i = prime_lower_bound; i <= user_upper_bound; ++i) { //Le nombre i va être notre variable testée et imprimée sur le terminal
            for (int j = prime_lower_bound; j <= largest_prime_factor; ++j) { //Cette boucle sert à tester si le nombre i a un diviseur plus petit que 31
                if (i % j == 0 && i != j) {
                    goto label;  //De cette façon je ne cout pas la variable à chaque fois que je sors de la boucle
                }
            }

            cout << '\t' << i << " ";
            if (++new_line % new_line_choice == 0) cout << endl; //On peut gérer quand l'affichage retourne à la ligne en changeant la variable new_line_choice

            label:
        }

        cout << endl << endl;

        do {
            cout << "Voulez-vous recommencer? [O/N] :";
            cin >> restart_program;
        } while (restart_program != "O" && restart_program != "N"); //On doit d'abord tester si l'entrée utilisateur est valide

    } while (restart_program == "O");

    cout << endl << "Au revoir!" << endl;


    return EXIT_SUCCESS;
}

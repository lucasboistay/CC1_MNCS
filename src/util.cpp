//
// Created by lucas on 15/02/2024.
//

#include "../include/util.h"

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;


void ecrit(const std::string nomfichier, const Eigen::VectorXf &h, const Eigen::VectorXf &delta){
    ofstream my_file; //declaration d 'un objet output file stream
    my_file.open(nomfichier); //connexion du flux au fichier

    if (! my_file) { //test de la reussite
        cerr << "Impossible d 'ouvrir " << nomfichier << endl;
        exit(EXIT_FAILURE);
    }

    //definition du format de sortie
    my_file << setiosflags(ios::scientific) << setprecision(7);

    //ecriture d'en tête
    int n = h.size();
    my_file << "#" << " " << "h min" << " " << h.minCoeff() << " " << " h max" << " " << h.maxCoeff() << "n" << n << endl;
    my_file << "#" << " " << "delta min" << " " << delta.minCoeff() << " " << " delta max" << " " << delta.maxCoeff() << endl;


    for (int i = 0; i < n; i++) {
        my_file << h(i) << " " << delta(i) << endl;
    }
    my_file.close(); //fermeture de la connexion

}
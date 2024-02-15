/*
 * Created on 15/02/2024
 * Author : Lucas BOISTAY, 3809291
 */

#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <cmath>

#include "../include/fcts.h"
#include "../include/methode.h"
#include "../include/fcts.h"
#include "../include/util.h"

using namespace std;
extern float k;

int main() {
    cout << setiosflags(ios::scientific) << setprecision(7);
    cout << "------- Début du programme -------" << endl;

    float h_min;
    float h_max;
    int nombre_iteration;
    k = 2;
    float t_0 = 0.5;

    cout << "Entrer le minimum, maximum de h puis le nombre d'itérations." << endl;
    cin >> h_min >> h_max >> nombre_iteration;
    cout << "Valeurs choisis pour h : [" << h_min << "," << h_max << "], avec " << nombre_iteration << " itérations." << endl;

    // test de la dérivée analytique de la fonction en t_0

    cout << "Valeur de la dérivée analytique de la fonction en t = 0.5 : " << d2cosh_kt(t_0) << endl; // doit être égal à 6.172
    cout << "Valeur de la dérivée numérique de la fonction en t = 0.5 : " << deriv2_3tc(cosh_kt, t_0, 0.0001) << endl; // doit être égal à 6.172

    float r = pow((h_max/h_min), 1./(nombre_iteration-1));

    Eigen::VectorXf h(nombre_iteration); // tableau des h
    Eigen::VectorXf delta(nombre_iteration); // tableau d'erreurs

    for (int i=0; i<nombre_iteration; i++){
        h(i) = h_min * pow(r, i); // affectation des valeurs du vecteur h
        // v Mettre en dessous l'affectation du vecteur delta v
        delta(i) = abs(d2cosh_kt(h(i)) - deriv2_3tc(cosh_kt, t_0, h(i)));
    }

    cout << "Premières valeures de delta : " << delta(0) << " " << delta(1) << " " << delta(2) << " " << delta(3) << " " << delta(4) << endl;

    // Ecriture dans un fichier erreur.txt

    ecrit("data/erreur.txt", h, delta);

    return 0;
}

import numpy as np
import matplotlib.pyplot as plt
import sys 

# Variable a modifier avant execution
nomfichier = "erreur.txt"                     # <== fichier de donnees
#nomfichier = "logistique.txt"                     # <== fichier de donnees

# ou bien indiquer le nom du fichier sur la ligne de commande
if len(sys.argv) > 1:
    nomfichier = sys.argv[1]

# Choix du nom du fichier de sortie : idem fic. entree avec extension .pdf
nomgraph = nomfichier[ : nomfichier.rfind(".")]+".pdf"

try:      # ouverture du fichier de donnees
  fich  = open(nomfichier, "r")
except:
  print(" ! Impossible d'ouvrir le fichier %s."%nomfichier )
  print(" ! Verifier le chemin.\n")
  exit()

# Lecture des lignes d'entete
ligne = fich.readline().replace("\n","") # sans caractere de fin de ligne
entete= [ ]
while( ligne[0] == "#" ):
   entete.append( ligne[1:] )
   ligne =  fich.readline().replace("\n","")
fich.close()
print( " > fichier %s : %d lignes d'entete"%( nomfichier, len(entete) ) )

# concatenation des entetes en une seule ligne de titre :
titre = " ".join(entete)

# Lecture des donnees du fichier :
tab = np.loadtxt( nomfichier, dtype="float")

# Creation des listes d'abscisses/ordonnees : 1ere et 2eme colonnes
x = tab[:,0]
y = tab[:,1]

# Creation du graphique
plt.figure( figsize=(11.69, 8.27) ) # taille en inches : A4 paysage
plt.title( titre, fontsize=8)
plt.grid()

plt.loglog(x, y, "o", label="D2C 3termes")                # <== choix de la legende
plt.xlabel("h")                                   # <== variable d'abscisse
plt.ylabel("delta")                                   # <== variable d'ordonnee

plt.legend()
plt.savefig(nomgraph) # sauvegarde du fichier.
print(" < Le graphique %s a ete cree."%(nomgraph) )
print("   \tVisualiser avec :  evince %s"%(nomgraph))

plt.clf() # nettoyage ('clear figure')

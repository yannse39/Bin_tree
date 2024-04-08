Mini Projet 2 Arbre Binaires

Ce projet est divisé en 4 exercice dont un Makefile qui permet de compiler nos fonctions par le biais de tests. Ce projet est une implémentation des arbres binaires avec différent type de parcours.

Notre Makefile propose ces différentes règles :

all : [Première règle] lance la règle libmybintree.
clean : supprime tous les fichiers temporaires et ceux créés par le compilateur.
dist : crée une archive propre, valide, et répondant aux exigences de rendu.
distclean : lance la règle clean, puis supprime les binaires et bibliothèques.
check : lance le(s) script(s) de test.
libmybintree : lance les règles shared et static
shared : compile l’ensemble du projet avec les options de compilations exigées et génère une bibliothèque dynamique.
static : compile l’ensemble du projet avec les options de compilations exigées et
génère une bibliothèque statique.

Installation

Dans le répertoire racine, exécutez la commande make. En outre, configure le script shell de configuration pour l’environnement de compilation.

License

GNU Licence.

Note: Assurez-vous d'avoir les droits d'exécution sur les fichiers avant de les utiliser.



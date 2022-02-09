Bienvenue dans la partie C du code.

 Testé avec : Dell Latitude 5420 munit d'un 11th Gen Intel® Core™ i7-1185G7 @ 3.00GHz × 8 ainsi que 7,5 GiB de RAM.

Version d'OS : Ubuntu 20.04.3 LTS 64 bits

Nom et Version du Compilateur : gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04) | Horner<Type>.c compilé avecl'option -lm -o | l’exécutable diveuclid est a jour.

Version de GNOME : 3.36.8
/---------------------------Polygen-----------------------------------/

Il s'agit d'une fonction qui génère un polynôme aléatoire. Elle prend en entrée le degré du polynôme ainsi que le point ou tester.

Pour le compiler : gcc PolyGen.c -o PolyGen
Pour l'executer et l'enregistrer dans le ficheir poly1.txt dans le fichier Horner : ./PolyGen >Horner/poly1.txt

/---------------------------Horner------------------------------------/

Le programme évalue avec deux méthodes la valeurs d'un polynome en un point, avec la méthode de Horner et avec la méthode classique (des puissances)

Les donnés doivent être rentrés dans valPolyE.txt avec en premier le degré, puis les valeurs des alphas puis le point ou evaluer le polynome.

Les donnés ainsi que le résultat est enregistré dans le fichier valpolyR.txt.
Le temps d’exécution du programme est aussi évalué, affiché et enregistré dans le fichier

Pour lancer le programme avec les valeurs de valPolyE et enregistrer les résultats dans valPolyR : ./Horner<Type> < valPolyE.txt >valpolyR.txt

/----------------------------Tchebychev-------------------------------/

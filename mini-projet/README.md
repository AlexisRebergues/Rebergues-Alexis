# Description du projet
- quel jeu a été modifié / étendu ou réalisé ?
- quelle(s) modifications, ... ?

Le jeu modifié est le snake. L'objectif du projet est d'ajouter un poison qui si l'on le touche lance le Game OVER. Au départ fixe, ce poison se mettra à se déplacer à la manière d'un snake dès lors
que la longueur du serpent devient importante. 
# Comment compiler

gcc -o code.exe code.c C:\raylib\raylib\src\raylib.rc.data -s -static -O2 -std=c99 -Wall -IC:\raylib\raylib\src -Iexternal -DPLATFORM_DESKTOP -lraylib -lopengl32 -lgdi32 -lwinmm

# Comment exécuter

cmd /c IF EXIST code.exe code.exe

# Comment utiliser le projet

Les commandes du jeu restent les mêmes pour l'utilisateur (simples mouvements de flèches).
Il n'y a qu'une règle qui y a été ajouté: si la tête du serpent entre en contact avec un des poisons, alors c'est Game Over?
![explication contact](https://user-images.githubusercontent.com/115557979/201527158-ff227b5c-e643-42de-bdc5-fef6bc3593ea.png)


# URL vidéo de démo
# Quelques détails sur votre implémentation
quel(s) fichier(s), structures de données, algorithme, ...
# Extensions / améliorations possibles

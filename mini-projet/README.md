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
Il n'y a qu'une règle qui y a été ajouté: si la tête du serpent entre en contact avec un des poisons, alors c'est Game Over.

![explication contact](https://user-images.githubusercontent.com/115557979/201527158-ff227b5c-e643-42de-bdc5-fef6bc3593ea.png)


# URL vidéo de démo

https://www.youtube.com/watch?v=EqMHM1fYCig


# Quelques détails sur votre implémentation
Un seul fichier contenant le code du jeu. Cependant de nombreux commentaires sont présents afin de rendre facile la lecture du code.

Dans le code nous avons :
- ajouté une structure de type Poison analogue à la struct de type Food
- complété le mouvement de serpent en ajoutant des conditions (if ) concernant la longueur du serpent (variable int Countertail) afin d'implémenter le déplacement du serpent (snake.speed)
- implémenté la génération aléatoire de la position de chaque poison (random) en ajoutant des conditions (boucle while) relançant la génération tant que la position du poison est égale à celle d'un autre poison ou de la nourriture
- implémenté le mouvement des poisons de manière aléatoire à l'aide de la variable int proba (boucles if) et d'un random ( (rand)%(4) dans notre cas )
- ajouté le dessin des différents poisons sur la fenêtre
- ajouté le score du joueur (variable int score) sur la fenêtre du Game Over

# Extensions / améliorations possibles

Ce jeu peut être complété par : 

- Plusieurs fenêtres s'affichant permettant de partitionner le passage d'un niveau à un autre puis relance du jeu avec niveau plus difficile (disons que si la longueur du serpent est de 5, alors on change de niveau)
- Ajout de plusieurs étapes intermédiaires (niveau sans poison, niveau avec poisons fixes, mouvement avec poison déterministe puis non deterministe, avec des niveaux de plus en plus rapides et une vitesse toujours plus élevée.


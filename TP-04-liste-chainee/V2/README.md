Comment compiler :
  gcc -Wall -o mySpotify mySpitofy.c linkedListOfMusic.c linkedList.c 
  
Comment exécuter:
  ./mySpotify

Comment observer les différences:
  
  
  ./mySpotify > liste

  diff liste  music.csv
  
Comment observer les fuites mémoires
    valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpotify


Observations:
    Il existe des fuites mémoires non résolue pour le moment

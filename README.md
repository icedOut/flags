# inf3135-ete2018-tp3


## Description

Le but de ce programme est d'afficher un ou plusieurs pays ainsi que leurs informations, selon les arguments entrées.

Voici les informations qui peuvent être afficher en option :

 - capitale du pays
 - langues officielles du pays
 - frontières avec les autres
 - drapeau du pays
 
Par défaut, le programme affiche l'ensemble des pays du monde. Cependant, il est possible de réduire l'Affichage a un seul pays ou un seul contient.

le projet utilise la base de donnée JSON du [project COUNTRIES](https://github.com/mledoze/countries)

Projet présenté a Mr. Alexandre Blondin, dans le cadre du cours INF3135 - à la session
d'été de l'UQAM

## Auteurs

- Philippe Chatrand (CHAP24059408)

**** note: l'etudiant Saad Aguenou était supposer faire le travail avec moi. il etait supposer faire la branche parse json. pendant 2 semaine, il affirmait qu'il avancait sur sa branche local
, cependant il na jamais commit des modifications. 5 jours avant la remise, il m'envoie un message pour me dire que ses modifications ne fonctionnent pas et que je ferais mieux de l'oublier pour le tp3. Je l'ai donc
supprimer du dépot et compléter le tp seul. Il a donc eu accès à mon dépot et a mon code source pendant 2 semaine. Je vous met en garde en cas ou il remettrait un TP de son coté avec du code semblable au mien.
Bref, j'aurais du écouter votre conseil lorsque vous disiez que les élèves qui n'ont pas d'équipes quelques jours après que l'énoncé ne sont pas les plus travaillant.



## Fonctionnement




Pour compiler le programme, entrez la commande `make`

Pour lancer la série de test, entrez la commande `make test`

Pour éxécuter le programme en mode par défault, entrez la commande `bin/tp3`.

Il est possible d'ajouter plusieurs options a l'éxécution du programme:

# UTILISATION

Pour lancer le programme, entrez la commande . les options entre entre [brackets] sont optionnelles.

  `bin/tp3 [--help] [--output-format FORMAT] [--show-languages] [--show-capital] [--show-borders] [--show-flag] [--country COUNTRY] [--region REGION]`

## ARGUMENTS OPTIONNELS

####  --help                 

Affiche le message d'aide et quitte 

#### --output-format FORMAT    

Choisir le format de sortie ( dot , png ou text ). le format reconnu par graphviz est dot. le format par défaut est text.

Pour l'option PNG, voir la section Rediriger la sortie vers un nouveau fichier.
                          
                             

#### --show-languages     
  
  afficher les langues parlées du pays
  
#### --show-capital                 

afficher les capitales
  
#### --show-borders            

afficher les frontières avec les autres pays
  
#### --show-flag                

afficher le drapeau du pays (seulement pour DOT et PNG)
                             
#### --country COUNTRY         

le code du pays a afficher ( ex : can , usa );
  
#### --region REGION           

le continent a afficher les continents supportées sont 
americas, africa, asia , europe et oceania

		 

## Rediriger la sortie vers un nouveau fichier 

#### NOMFICHIER 
le nom du fichier sortant. 

 Ceci n'est pas un argument a utiliser pour appeler le programme,
mais plutôt utiliser lors d'un appel avec redirection :
par exemple, si vous voulez conservez les informations du canada en format dot, entrez la commande:


` bin/tp3 --output-format dot --country can --show-languages --show-borders --show-capital > NOMFICHIER.dot`

Pour exporter le graphique DOT en format PNG, entrez la commande :

` dot -Tpng NOMFICHIER.dot >  NOMFICHIER.png `

Si vous désirez conservez la sortie en mode texte, entrez la commande :

` bin/tp3 --output-format dot --country can --show-languages --show-borders --show-capital > NOMFICHIER.txt`



## Plateformes supportées

-Linux

-Mac os


## Dépendances

- [bibliothèque Jansson](http://www.digip.org/jansson/)

- [bibliothèque CUNIT (tests)](http://cunit.sourceforge.net/)

- [Graphviz](https://graphviz.gitlab.io/)


## Références

- INF3135 - Notes de Cours (Alexandre Blondin-Massé)
- INF3135 - tp2 (Alexandre Blondin-Massé)
- [project COUNTRIES](https://github.com/mledoze/countries)

## Division des tâches


- [x] Coquille de base 
- [x] Makefile
- [x] Parsage des arguments 
- [x] Tests parsage arguments 
- [x] Parsage JSON 
- [x] Tests bats 
- [x] Affichage Text
- [x] Affichage dot
- [x] Affichage PNG


 

## État du projet

EN cours de développement



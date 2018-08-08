# inf3135-ete2018-tp3


## Description

Description du projet en quelques phrases.

Projet présenté a Mr. Alexandre Blondin, dans le cadre du cours INF3135 - à la session
d'été de l'UQAM

## Auteurs

- Philippe Chatrand (CHAP24059408)



## Fonctionnement

Le but de ce programme est d'afficher un ou plusieurs pays ainsi que leurs informations, selon les arguments entrées.

Pour compiler le programme, entrez la commande `make`

Pour lancer la série de test, entrez la commande `make test`

Pour éxécuter le programme en mode par défault, entrez la commande `bin/tp3`.

Il est possible d'ajouter plusieurs options a l'éxécution du programme:

# UTILISATION

`bin/tp3 [--help] [--output-format FORMAT] [--output-filename FILENAME]

 	[--show-languages] [--show-capital] [--show-borders] [--show-flag]
 	
 	[--country COUNTRY] [--region REGION]`

## ARGUMENTS OPTIONNELS

####  --help                 

Affiche le message d'aide et quitte 

#### --output-format FORMAT    

Choisir le format de sortie ( dot , png ou text ). le format reconnu par graphviz est dot. le format par défaut text.
                             
#### --output-filename FILENAME 

le nom du fichier sortant. Cet argument est obligatoire
 pour le format PNG. Si non spécifié en mode TEXT ou dot,
 le programme affichera sur la sortie standard.
  							 
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

## Division des tâches


- [x] Coquille de base (Phil)
- [x] Parsage des arguments (Phil)
- [x] Tests parsage arguments (Phil) 
- [ ] Parsage JSON (Saad)
- [ ] 

 

## État du projet

EN cours de développement



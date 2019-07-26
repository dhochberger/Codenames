# **PROJET IMH** :purple_heart: :yellow_heart: :blue_heart: :green_heart: :heartbeat: :heartpulse: :two_hearts: :revolving_hearts: :cupid: :sparkling_heart: :gift_heart: :heart_decoration:
![Codenames logo](https://www.magicbazar.fr/images/codenames-logopng.png)
### _Groupe 12_ :ok_hand: :100:
#### Chef de projet : KNAPP Liesse :sunglasses:

**Membres**|**Module.s**
--|--
ARMAND Lyne :dog:| **Graphique** / Réseau
HOCHBERGER Dylan :muscle:|Graphique
KNAPP Liesse :poop:|**Noyau** / Réseau
LEGROS Mélanie :hear_no_evil:|Graphique
MASSE Robin :cat:|**Noyau** / Réseau

***

## **INTRODUCTION**

> L'objectif de ce projet est de réaliser un jeu de carte nommé Codenames en proposant un noyau de jeu et une interface graphique afin de le mettre en forme.
> Pour remplir cet objectif, nous avons choisi comme implémentation une architecture MVC.
Le projet est donc constitué d'une architecture en trois interfaces.</p>
* Un classique Modèle-Vue-Contrôleur pour la version locale. </li>
* Pour la version en ligne, l'ensemble de la version local servira en quelque sorte de vue pour le serveur, ayant lui même son propre modèle et contrôleur.</li>

"Ok mais Codenames qu'es ce que c'est?"

[![youtube image of the video](http://img.youtube.com/vi/szYTmx0bYyw/0.jpg)](http://www.youtube.com/watch?v=szYTmx0bYyw)

## **SECTION CLIENT**

Pour réaliser l'architecture de la section client, nous auront donc nos multiples interfaces qui communiqueront comme présenté ci-dessous :

### MODELE

> Le Modèle conservera le plateau de jeu, les cartes qui l'occupent ainsi que les options de l'application tel que le volume, les couleurs des équipes ainsi que les options des serveurs de jeux dans le cas de la version en ligne.
Les changements envoyés par le Contrôleur seront sauvegardés dans le modèle afin d'être lus par la Vue.

### VUE

>  La Vue servira d'interface à l'utilisateur afin qu'il puisse jouer, regarder et sélectionner les cartes, ainsi que modifier les réglages et les options de son application ou de sa future partie en ligne.
Elle usera du contrôleur pour récupérer les informations présentent dans le modèle ou pour y appliquer les modifications découlant des choix de l'utilisateur.

### CONTROLEUR

Le Contrôleur servira de "boîte à outils" afind de réaliser toutes les opérations potentielles que l'utilisateur au travers de la Vue pourrait désirer accomplir.

> Voici les fonctions du Contrôleur qui sont utilisable pour intéragir avec le jeu :
(La variable 'c' est utiliser à titre d'exemple)
* ```Controller c=Controller()``` qui permet de générer le contrôleur. (A faire impérativement avant de pouvoir en utiliser d'autres)
* ```c.isTeamOnePlaying()``` qui retournera un booléen pour savoir si l'équipe 1 joue actuellement ou pas. Si la partie n'a pas encore commencé le booléen indique si l'équipe 1 commence ou non.
* ```c.blockColor(int idBlock)``` qui peut retourner 0,1,2 ou 3 si la carte correspondant à l'idBlock fourni est respectivement un témoin neutre,un agent de l'équipe 1, un agent de l'équipe 2 ou l'assassin.
* ```c.blockWord(int idBlock)``` qui retourne une chaîne de caractère, celle contenu sur la carte d'idBlock.
* ```c.isBlockSelected(int idBlock)``` qui retourne un booléen afin de déterminer si une carte à déjà été joué, celle indiqué son idBlock.
* ```c.playBlock(int idBlock)``` qui peut retourner 0,1 ou 2 si la carte correspondant à l'idBlock fourni une fois jouer soit ne fait gagner aucune équipe, fait gagner l'équipe 1 ou la 2.
* ```c.newMap()``` qui génére un nouveau plateau de jeu si on décidait de faire une deuxième, troisième, trentième partie car on veut une revanche sur ce jeu très prennant par exemple.
              
> Un ensemble de getters ```c.get...()``` et de setters ```c.set...(...)``` afin d'intéragir avec les options de l'application :
* la langue avec ```Language``` de type ```string```.
* le volume principale avec ```MasterVolume``` et ```OldMasterVolume``` de type ```int```.
* le volume de la musique avec ```MasterVolume``` et ```OldMusicVolume``` de type ```int```.
* le volume des effets avec ```EffectVolume``` et ```OldEffectVolume``` de type ```int```.
* la couleur de l'équipe 1 avec ```ColorTeamOne``` de type ```string```.
* la couleur de l'équipe 2 avec ```ColorTeamTwo``` de type ```string```.


> autres fonctions intéragissant avec les options de l'application :
* ```c.mute()``` qui met les différents volumes à zéro et ```c.unmute()``` qui restore les niveaux des anciens volumes.
* ```c.isVolumeMuted()``` et ```defaultSettings()```qui sont explicite.

> Des fonctions permettant configuerer les options d'une partie en ligne :
* 

> et des fonctions permettant de communiquer avec la section serveur par échange de paquets à l'aide du protocole TCP/IP :
* 
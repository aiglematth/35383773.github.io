﻿# Challenge 05/08/2020

Ce write-up concerne le challenge du 05/08/2020 obtenu à l'adresse : 
https://twitter.com/CTF_Inter_IUT/status/1291026187595194370

![](./Images/05-08-2020(1).png)


## Mots-clés

Tout d'abord, nous devons prendre en considérations les mots-clés de la problématiques.
Nous pouvons noter "profil Firefox" ou encore "suspecte".
Cela signifie que nous devons analyser un profil Firefox afin de trouver quelque chose de suspect.


## Exploitation

Dans un premier temps, nous tapons dans notre barre de recherche les mots suivants : **about:profiles**. 
On sélectionne le bouton "Create a New Profile", puis importons le répertoire préalablement extrait de l'archive de m'sieur LaPoutre.

![](./Images/05-08-2020(2).png)

Une fois terminé, nous fermons notre navigateur puis tapons dans notre terminal la commande : <code>firefox -P</code>. 
Cette dernière nous permet de sélectionner notre profil concerné.

Après lancement du navigateur, la première chose à faire est de fouiller dans les marques-pages du profil. 
Rapellons que nous recherchons quelque chose de suspect.

![](./Images/05-08-2020(3).png)

*Et franchement.. il n'y a rien de concluant !*

C'est donc sur ce pas que nous nous dirigeons sur le jardin secret de ce bon vieux LaPoutre, j'ai nommé : l'historique !

![](./Images/05-08-2020(4).png)

Après quelques petites recherches nous tombons sur une ligne plutôt intéressante :

https://challs.hack2g2.fr/voici_une_page_pas_du_tout_suspecte_que_vous_pourriez_peut_etre_aller_verifier

C'est ainsi que notre instinct nous dit de cliquer sur ce lien et.. PAF, un flag de plus !

<code>ENSIBS{w4sH_*}</code>




#### Auteur : Onid1

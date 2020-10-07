# C'est partie pour une initiation à l'exploitation de binaire

## Euu...l'exploitation de quoi ?
L'exploitation de binaire c'est un mot rassemblant trois disciplines :
- Le reverse engineering = Comprendre le fonctionnement d'un programme
- Le pwn                 = Exploiter un programme en cours d'éxecution pour dévier son comportement
- Le cracking            = Exploiter un programme arrêté pour dévier son comportement
Chacune est intimement reliée aux autres

## Qu'est ce qu'on va faire aujourd'hui ?
Je pense que vous l'avez compris, on est parti pour une (minuscule) introduction à l'exploitation de binaire. Donc, comme aujourd'hui c'est de l'initiation, on va pas se gêner pour regarder le code du programme.

## Quel programmme ?
```c
#include <stdio.h>

void vuln(void)
{
	//OMIS...FAUT PAS POUSSER MEME DANS LES ORTIES !!
}

int main(void)
{
	int impossible = 1;

	printf("Vous n'aurez jamais mon flag !!!!\n");
	if(impossible == 0)
	{
		vuln();
	}

	return 0;
}
```
Bon, on voit bien qu'il y a un soucis, jamais on ne va entrer dans le bloc if, car 1 == 0 est faux ! Le principe va être d'appliquer un patch au programme afin qu'il ne fasse plus de jump après vérification. Pour faire simple, le nouveau programme sera :
```lang-c
#include <stdio.h>

void vuln(void)
{
	//OMIS...FAUT PAS POUSSER MEME DANS LES ORTIES !!
}

int main(void)
{
	int impossible = 1;
	printf("Vous n'aurez jamais mon flag !!!!\n");
	vuln();

	return 0;
}
```
Génial non ??

## Dans la pratique !
Dans la pratique, on va devoir modifier le code assembleur du binaire...Bon là on va pas trop entrer dans les détails, mais il faut savoir que ca en C :
```lang-c
if(impossible == 0)
{
	vuln();
}
//Après le IF
```
C'est ca en assembleur (simplifié pour plus de compréhension):
```lang-nasm
cmp    impossible, 0x0
jne    apresLeIf
call   vuln
apresLeIf  
```
Donc si vous avez suivi, on va remplacer la ligne jne par une ligne où on dit à notre ordinateur de ne rien faire...En assembleur, ne rien faire c'est nop (No OPeration). Voici le code modifié :
```lang-nasm
cmp    impossible, 0x0
nop    
call   vuln
apresLeIf   
```
On va s'épargner les détails techniques...et lancer le script qui patch notre programme...
Maintenant...on lance le programme patché...WAAAAOWWWW !!!! On est vraiment trop fort !!!!


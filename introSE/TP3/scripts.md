> Tous les fichiers ([Taux](/introSE/TP3/ressources/Taux), [a_convertir](/introSE/TP3/ressources/Taux/a_convertir)) sont situés dans le dossier [ressources](/introSE/TP3/ressources).
> 

# Script n°1

```bash
echo "###########################################"
echo ""
echo "La ligne de commande comporte $# paramètres"
echo ""
echo "Execution de la commande: $0"
echo ""
echo "Avec les paramètres: $*"
echo ""
echo "###########################################"
```

# Script n°2

```bash
echo "###########################################"
echo ""
echo "La ligne de commande comporte $# paramètre(s)"
echo ""
echo "Execution de la commande: $0"
echo ""
echo "Avec les paramètres: $*"
echo ""
echo "###########################################"
echo ""
timesc=$(last $1 | wc -l)
devicename=$(hostname)
echo "L'utilisateur $1 s'est connecté $timesc fois sur $devicename."
echo ""
last3c=$(last $1 | head -n 3)
echo -e "Ces trois connexions on été aux dates suivantes:\n$last3c"
echo ""
```

# Script n°3

## 1.

```bash
if [ -e Taux ]
then
	if [ $# -eq 1 -a a$1 = "a-e" ]
	then
		echo -n "Somme en francs: "
		read francs
		taux="$(cat Taux | tr ':', '\n' | tail -n 1)"
		echo "Valeur en euros: $(echo "$francs/$taux" | bc -l)"
	else
		echo -n "Somme en euros: "
		read euros
		taux="$(cat Taux | tr ':' '\n' | tail -n 1)"
		echo "Valeur en francs: $(echo "$taux*$euros" | bc)"
	fi
else
	exit 1
fi
```

## 2.

```bash
if [ -e Taux ]
then
	taux="$(cat Taux | tr ':', '\n' | tail -n 1)"
	if [ $# -eq 1 -a a$1 = "a-e" ]
	then
 		echo -n "Somme en francs: "
 		read francs
 		echo "Valeur en euros: $(echo "$francs/$taux" | bc -l)"
	elif [ $# -eq 2 -a a$1 = "a-f" -a a$2 != "a" ]
	then
		if [ -e $2 ]
		then
			while read lne
			do
				echo "Valeur en francs: $(echo "$taux*$lne" | bc)"
			done < $2
		else
				exit 1
		fi
	elif [ $# -eq 3 -a a$1 = "a-e" -a a$2 = "a-f" -a a$3 != "a" ]
	then
		if [ -e $3 ]
		then
			while read lne
			do
	 			echo "Valeur en euros: $(echo "$lne / $taux" | bc -l)"
			done < $3
		else
				exit 1
		fi
	else		
 		echo -n "Somme en euros: "
 		read euros
 		echo "Valeur en francs: $(echo "$taux*$euros" | bc)"
	fi
else
	exit 1
fi
```
# Script 1

```bash
rep="./"
if [ $# -eq 1 ]
then
	rep="$1"
elif [ $# -gt 1 ]
then
	echo "Vous ne devez fournir qu'un seul paramètre."
	exit
fi

sum=0
for file in $(ls $rep)
do
	echo "$file, $(stat -c %s $rep/$file)"
	sum=$(echo "$sum+$(stat -c %s $rep/$file)" | bc)
done
echo "$sum"
```

# Script 2

```bash
if [ $# -ne 1 ]
then
	exit
elif [ -f $1 ]
then
	total=0
	nbNotes=0
	max=$(head -n 1 $1)
	min=$(head -n 1 $1)
	while read line
	do
		nbNotes=$nbNotes+1
		if [ $line -gt $max ]
		then
			max=$line
		elif [ $min -gt $line ]
		then
			min=$line
		fi
		total=$total+$line
	done < $1
	echo "Moyenne: $(echo "$total/$nbNotes" | bc -l)"
	echo "Max: $max"
	echo "Min: $min"
else
	exit
fi
```

# Script 3

```bash
if [ $# -eq 2 ]
then
	if !(test -d $2)
	then
		$(mkdir $2)
	fi
	for file in $(ls *$1)
	do
		$(mv $file $2/$file)
	done
else
	exit
fi
```
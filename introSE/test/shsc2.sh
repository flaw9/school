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
		nbNotes=$(echo "$nbNotes+1" | bc)
		if [ $line -gt $max ]
		then
			max=$line
		elif [ $min -gt $line ]
		then
			min=$line
		fi
		total=$(echo "$total+$line" | bc)
	done < $1
	echo "Moyenne: $(echo "$total/$nbNotes" | bc -l)"
	echo "Max: $max"
	echo "Min: $min"
else
	exit
fi

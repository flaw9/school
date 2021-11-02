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

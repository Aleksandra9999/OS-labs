if test ! -f numbers
then
    echo 0 > numbers
fi


if ln numbers numbers.lock
	then
	for i in `seq 1 300`;
	do
		last=`tail -1 numbers`
		last=$((last+1))

		echo $last >> numbers
	done

	rm numbers.lock
fi
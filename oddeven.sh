echo  "Enter a number:"
read n
echo  "RESULT: "
if [ `expr $n % 2` == 0 ]
then
	echo "$n is even"
else
	echo "$n is Odd"
fi


echo "Enter Num1"
read num1
echo "Enter Num2"
read num2

if [ $num1 -gt $num2 ]
then
    echo "Greatest Number: $num1"
elif [ $num2 -gt $num1 ]
then
    echo "Greatest Number: $num2" 
else
    echo "Both are Equal"
fi

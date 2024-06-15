echo "Kindly Enter a number"
read num
temp=$num
fact=1
while [ $num -gt 1 ]
do
  fact=$((fact * num))  
  num=$((num - 1))      
done
echo -e
echo "Factorial of $temp is: $fact"

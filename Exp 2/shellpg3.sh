echo "Kindly enter a number"
read num
temp=$num

sum=0
while [ $num -gt 0 ]
do
    mod=$((num % 10))  
    sum=$((sum + mod))
    num=$((num / 10))
done
echo -e
echo "Sum of individual digits of $temp is: $sum"

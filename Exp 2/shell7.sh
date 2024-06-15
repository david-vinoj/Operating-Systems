echo "Kindly enter a no"
read num
echo -e
for((i=1;i<=num;i++))
do
	sum=$((sum + i))
done
echo "Sum of first $num digits is: $sum"

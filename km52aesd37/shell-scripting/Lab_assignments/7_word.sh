#
read -p "Enter file name:" file
read -p "Enter word:" word
echo "file before removing:" $word
cat $file
grep -v -i $word $file > test
mv test $file
echo file after removing $word:
cat $file

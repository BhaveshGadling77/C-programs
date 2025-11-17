i=0
git init
git add .
git commit -m "first commit added the script file"
git checkout -b newBranch
git checkout -b $1
while [ $i -le $2 ]
do
    git checkout -b $1$i
    cat "branch$i" > tmp$i
    git add .
    git commit -m "commiting on branch $1$i"
    i=$((i + 1))
    git checkout $1
done
git checkout main

i=$(($2 - 1))
git checkout $1$i
while [ $i -ge 0 ]
do
	git merge $1$((i + 1)) -m "merging $1$((i + 1)) into $1$i"
	echo "merging $1$((i + 1)) into $1$i"
	i=`expr  $i - 1`
	git checkout $1$i
done
git checkout newBranch
git merge $10 -m "merging the final branch"

git log --oneline --graph --decorate --color

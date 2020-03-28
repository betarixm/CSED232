rm -rf ./dist
mkdir ./dist
mkdir ./dist/20190084

for i in 1 2 3
do
  mkdir ./dist/20190084/prob_$i
  cp ./prob_$i/prob_$i.cpp ./dist/20190084/prob_$i/prob_$i.cpp
done

cp ./Makefile ./dist/20190084/Makefile
cp ./20190084.pdf ./dist/20190084/20190084.pdf
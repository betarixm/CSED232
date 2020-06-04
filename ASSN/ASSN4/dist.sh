rm -r ./dist
mkdir ./dist

cp ./*.h ./dist/
cp ./report/20190084.pdf ./dist/

cd dist
zip 20190084.zip ./*
rm -r ./dist
mkdir ./dist
mkdir ./dist/source

cp ./*.cpp ./dist/source/
cp ./*.h ./dist/source/
cp ./report/assn3_report.* ./dist/
cp ./Makefile ./dist/source/Makefile
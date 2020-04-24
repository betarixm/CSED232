rm -r ./dist
mkdir ./dist
mkdir ./dist/source

cp ./*.cpp ./dist/source/
cp ./*.h ./dist/source/
cp ./report/assn2_report.* ./dist/
cp ./Makefile ./dist/source/Makefile
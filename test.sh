CUR_PATH=`pwd`
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CUR_PATH/depend/NLP/lib/
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CUR_PATH/depend/chardet/lib/
cd ./bin
./nlpir
cd ..

if exist cat_v2.exe (
    del cat_v2.exe
)

cd ..
cmake --build .
cd cat_v2

if exist cat_v2.exe (
    start cat_v2.exe
)   

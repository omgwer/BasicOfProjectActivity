if exist cat_v3.exe (
    del cat_v3.exe
)

cd ..
cmake --build .
cd cat_v3

if exist cat_v3.exe (
    start cat_v3.exe
)   

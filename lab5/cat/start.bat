if exist cat.exe (
    del cat.exe
)

cd ..
cmake --build .
cd cat

if exist cat.exe (
    start cat.exe
)   

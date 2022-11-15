if exist cat.exe (
    del cat.exe
)

cmake --build .

if exist cat.exe (
    start cat.exe
)   

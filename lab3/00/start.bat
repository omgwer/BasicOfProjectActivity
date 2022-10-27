if exist 00.exe.exe (
    del 00.exe
)

cd ..
    cmake --build .
cd 00

if exist 00.exe (
    start 00.exe
)   

if exist 01.exe (
    del 01.exe
)

cd ..
    cmake --build .
cd 01

if exist 01.exe (
    start 01.exe
)   

if exist 03.exe (
    del 03.exe
)

cd ..
    cmake --build .
cd 03

if exist 03.exe (
    start 03.exe
)
    

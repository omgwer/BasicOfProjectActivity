if exist 02.exe.exe (
    del 02.exe
)

cd ..
    cmake --build .
cd 02

if exist 02.exe (
    start 02.exe
)   

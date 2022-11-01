if exist 05_sfml1_3.exe (
    del 05_sfml1_3.exe
)

cd ..
    cmake --build .
cd 05_sfml1_3

if exist 05_sfml1_3.exe (
    start 05_sfml1_3.exe
)   

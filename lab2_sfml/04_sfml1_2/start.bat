if exist 04_sfml1_2.exe (
    del 04_sfml1_2.exe
)

cd ..
    cmake --build .
cd 04_sfml1_2

if exist 04_sfml1_2.exe (
    start 04_sfml1_2.exe
)
    

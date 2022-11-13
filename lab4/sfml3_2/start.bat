if exist sfml3_2.exe (
    del sfml3_2.exe
)

cd ..
    cmake --build .
cd sfml3_2

if exist sfml3_2.exe (
    start sfml3_2.exe
)   

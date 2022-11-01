if exist sfml2_1.exe (
    del sfml2_1.exe
)

cd ..
    cmake --build .
cd sfml2_1

if exist sfml2_1.exe (
    start sfml2_1.exe
)   

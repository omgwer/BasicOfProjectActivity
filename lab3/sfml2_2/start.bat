if exist sfml2_2.exe (
    del sfml2_2.exe
)

cd ..
    cmake --build .
cd sfml2_2

if exist sfml2_2.exe (
    start sfml2_2.exe
)   

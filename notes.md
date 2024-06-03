# Compile
## Emscripten
`em++ MatrixMultiplication.cpp -mavx -msimd128 -o MatrixMultiplication.wasm`
## C++
`g++ -mavx MatrixMultiplication.cpp -o MatrixMultiplication`

# Run
## Emscripten
`{runtime} MatrixMultiplication.wasm`
## C++
`./MatrixMultiplication`
> The rows and columns for each matrix can be provided as arguments `rowsA colsA rowsB colsB



g++ {File}.cpp -mavx -o {File}
em++ {File}.cpp -mavx -msimd128 -o {File}.wasm

em++ -mavx -msimd128 -o benchmark.wasm benchmark.cpp  MatrixAddition.cpp helper.cpp dotProduct.cpp MatrixMultiplication.cpp
g++ -mavx -o benchmark benchmark.cpp  MatrixAddition.cpp helper.cpp dotProduct.cpp MatrixMultiplication.cpp
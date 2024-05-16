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



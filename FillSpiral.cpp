template<class T>
void FillSpiral(T**& matrix, int32_t size)
{
    int32_t limit = size - 1;    
    int32_t row{};    
    int32_t col{};
    int32_t layer{};
    
    while (limit >= 2) {
        
        for (size_t i = layer; i < limit; i++) {
            std::cout << "Enter value for [" << row << "][" << i << "]: ";
            std::cin >> matrix[row][i];
        }
        
        for (size_t i = layer; i < limit; i++) {
            std::cout << "Enter value for [" << i << "][" << limit << "]: ";
            std::cin >> matrix[i][limit];
        }
        
        for (size_t j = limit; j > layer; j--) {
            std::cout << "Enter value for [" << limit << "][" << j << "]: ";
            std::cin >> matrix[limit][j];
        }
        
        for (size_t j = limit; j > layer; j--) {
            std::cout << "Enter value for [" << j << "][" << row << "]: ";
            std::cin >> matrix[j][row];
        }
        
        --limit;
        ++row;
        ++layer;
    }
    
    int32_t center = size / 2;
    std::cout << "Enter value for [" << center << "][" << center << "]: ";
    std::cin >> matrix[center][center];
}

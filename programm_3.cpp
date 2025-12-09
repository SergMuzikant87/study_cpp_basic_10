#include <iostream>

int ** create_two_dim_array(const unsigned int rows, const unsigned int cols);
void fill_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols);
void print_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols);
void delete_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols);
int check_two_dim_array(int ** array, const unsigned int rows);

unsigned int array_of_char_to_int(const char * str);

int main(int argc, char * argv[])
{
    #define ROWS_DEFAULT 10
    unsigned int rows {(argc >= 2) ? array_of_char_to_int(argv[1]) : ROWS_DEFAULT};
    unsigned int cols {(argc >= 3) ? array_of_char_to_int(argv[2]) : rows};
    
    int ** array = create_two_dim_array(rows, cols);
    if(int er = check_two_dim_array(array, rows))
    {
        std::cout << "ERROR!!!\n";
        return er;
    }

    fill_two_dim_array(array, rows, cols);
    print_two_dim_array(array, rows, cols);
    delete_two_dim_array(array, rows, cols), array = nullptr;

    return 0;
}

int ** create_two_dim_array(const unsigned int rows, const unsigned int cols)
{
    int ** array = new int*[rows];
    if(array != nullptr)
    {
        for(unsigned int row_cur = 0; row_cur < rows; row_cur++)
        {
            array[row_cur] = new int[cols];
        }
    }
    return array;
}

void fill_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols)
{
    for(unsigned int row_cur = 0; row_cur < rows; row_cur++)
    {
        for(unsigned int col_cur = 0; col_cur < cols; col_cur++)
        {
            array[row_cur][col_cur] = (row_cur + 1) * (col_cur + 1);
        }
    }
}

void print_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols)
{
    for(unsigned int row_cur = 0; row_cur < rows; row_cur++)
    {
        for(unsigned int col_cur = 0; col_cur < cols; col_cur++)
        {
            std::cout << array[row_cur][col_cur] << "\t";
        }
        std::cout << std::endl << std::endl << std::endl;
    }
}

void delete_two_dim_array(int ** array, const unsigned int rows, const unsigned int cols)
{
    for(unsigned int row_cur = 0; row_cur < rows; row_cur++)
    {
        delete[] array[row_cur];
    }
    
    delete[] array;
}

int check_two_dim_array(int ** array, const unsigned int rows)
{
    if(array == nullptr)
    {
        return -1;
    }

    for(unsigned int row_cur = 0; row_cur < rows; row_cur++)
    {
        if(array[row_cur] == nullptr)
        {
            return -2;
        }
    }

    return 0;
}

unsigned int array_of_char_to_int(const char * str)
{
    unsigned int result = 0;
    
    while(char symbol = *str++)
    {
        result += (unsigned int)((symbol >= '0') && (symbol <= '9')) * ((result * 9) + (unsigned int)(symbol - '0'));
    }

    return result;
}


#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstdint>
#include <memory>
#include <vector>

template<typename T>
class matrix{
    private:
        std::vector<std::unique_ptr<T[]>> data;
        int cols,rows;
    public:
        matrix(int cols,int rows){
            data = std::vector<std::unique_ptr<T[]>>(rows);
            for(auto i:data){
                i.push_back(std::make_unique(new T[cols]));
            }
        }
        ~matrix()=default;
        matrix& operator=(matrix& other){
            other.data = data;
            other.rows = rows;
            other.cols = cols;
        }
        T& get(int r_index,int c_index){
            return data[r_index][c_index];
        }
        int getCols(){
            return cols;
        }
        int getRows(){
            return rows;
        }
};

#endif

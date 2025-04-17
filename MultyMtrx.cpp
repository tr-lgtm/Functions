template<class T>
  T** MultyMtrx(T** mtrxFirst, int32_t rowsFirst, int32_t colsFirst, T** mtrxSecond, int32_t rowsSecond, int32_t colsSecond){


      if(colsFirst != rowsSecond){
          throw std::invalid_argument("Invaled size of first rows and second cols");
      }

      int32_t** mtrx{};
      CreateDynamicMtrx(mtrx,rowsFirst,colsSecond);

      for (size_t i = 0; i < rowsFirst; i++)
      {
          for (size_t j = 0; j < colsSecond; j++)
          {
              for (size_t g = 0; g < colsFirst; g++)
              {
                  mtrx[i][j] += mtrxFirst[i][j] * mtrxSecond[g][j];
              }
          }
      }
      
      return mtrx;

  }

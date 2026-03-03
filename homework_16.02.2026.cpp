#include <cstddef>

template< class T >
T* merge(const T* const* a, size_t sa, const size_t* sai, T* c) 
{
    size_t tot_Size = 0;
    for (size_t i = 0; i < sa; ++i) 
    {
      tot_Size += sai[i];
    }
    size_t* curr = new size_t[sa];
    for (size_t i = 0; i < sa; ++i) 
    {
      curr[i] = 0;
    }
    T* out = c;
    for (size_t i = 0; i < tot_Size; ++i) 
    {
      bool found = false;
      size_t idx = 0;
      for (size_t j = 0; j < sa; ++j) 
      {
        if (curr[j] < sai[j]) 
        {
          if (!found || a[j][curr[j]] < a[idx][curr[idx]]) 
          {
            idx = j;
            found = true;
          }
        }
      }
      *out = a[idx][curr[idx]];
      ++out;
      ++curr[idx];
  }
  delete[] curr;
  return out;
}
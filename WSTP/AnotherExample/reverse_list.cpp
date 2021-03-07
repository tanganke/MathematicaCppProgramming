#include "wstp.h"
#include <stdint.h>

inline int WSPut(WSLINK link, int32_t i)
{
    return WSPutInteger32(link, i);
}

inline int WSPut(WSLINK link,double d)
{
    return WSPutReal64(link, d);
}

template <typename T, typename L>
inline void _reverse_list(T *data, L len)
{
    WSPutFunction(stdlink, "List", len);
    for (L i = len - 1; i >= 0; i--)
    {
        WSPut(stdlink,data[i]);
    }
}

void reverse_list(int32_t* data,long len)
{
    _reverse_list(data,len);
}

void reverse_list(double* data,long len)
{
    _reverse_list(data,len);
}
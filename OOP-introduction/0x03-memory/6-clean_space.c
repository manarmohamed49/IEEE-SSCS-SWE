#include <stdlib.h>
#include <stddef.h>
void *clear_allocation(size_t count, size_t size);
{
size_t  total_size= count * size ;
void *ptr =malloc(total_size);
if (ptr == NULL)
return NULL;
unsigned char *byte_ptr = (unsigned char *)ptr;
for (size_t i=0 ; i < total_size ; i++)
byte_ptr[i] = 0;
return ptr;
}

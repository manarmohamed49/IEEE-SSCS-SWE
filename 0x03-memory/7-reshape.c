#include <stdlib.h>
#include <stddef.h>
void *_reshape(void *ptr, size_t old_size, size_t new_size);
{
if(ptr == NULL)
return malloc(new_size);
if (new_size == 0)
{
free(ptr);
return NULL;
}
size_t min_size = old_size < new_size ? old_size : new_size;
unsigned char *src =(unsigned char *)ptr;
unsigned char *dest =(unsigned char *)new_ptr;
for (size_t i=0 ; i < min_size ; i++)
dest[i] = src[i];
free(ptr);
return new_ptr;
}

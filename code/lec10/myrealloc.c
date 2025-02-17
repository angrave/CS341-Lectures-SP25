void * myrealloc(void* old, size_t newsize) {
  if(!old) {return malloc(newsize);}

  entry_t* oldentry = ((entry_t*)old) - 1;
  
  void* new = malloc(newsize);
  memcpy(new,old, min(size,oldentry->size));
  free(old); old = NULL;
    
  return new;
}
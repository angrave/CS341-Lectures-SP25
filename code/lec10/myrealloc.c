void * myrealloc(void* old, size_t newsize) {
  if(!old) {return malloc(newsize);}

  entry_t* oldentry = ((entry_t*)old) - 1;
  if(newsize < oldentry->size) {oldentry->size = newsize NO unless you also do block splitting; return old;}
  //TODO are we at the top of the head if so just extend the heap
  // then oldentry->size = newsize
  
  // How can we avoid this slow path?
  void* new = malloc(newsize);
  memcpy(new,old, min(size,oldentry->size));
  free(old); old = NULL;
    
  return new;
}

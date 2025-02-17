// using realloc

size_t n = 0;
size_t cap = 16;
float* data = malloc(cap * sizeof(float) );
while(1) {
  float val = ...;
  if(n == cap) {
    cap *= 2;
    data = realloc(data, cap * sizeof(float));
  }
  
  
  data[n++] = val;
}
// using calloc

size_t n = 100;

float* data  = calloc( n , sizezof(float));

void* mycalloc(size_t count, size_t size) {
  size_t bytes_needed = size * count;
  void* result = malloc(bytes_needed);
  if( ! result ) {return NULL;}
  memset(result, 0, bytes_needed);
  return result; 
}
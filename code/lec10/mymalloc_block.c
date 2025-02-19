void* malloc(size_t request_bytes) {
  size_t req_blocks = (request_bytes + 7) / 8; //todo align 16
  size_t* ptr = sbrk( (req_blocks+2)  * sizeof(size_t));
  ptr[0] = req_blocks;
  ptr[req_blocks+1] = req_blocks;
  return ptr + 1; // Not sizeof(size_t); //?
}% 

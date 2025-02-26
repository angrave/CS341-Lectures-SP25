
task_t* buffer[16];

sem_t numspaces, numitems;

init() {
  sem_init( &numspaces ,0/*pshared*/, 16);
  sem_init( &numitems ,0/*pshared*/ , 0); 
  pthread_mutex_init(&m, NULL);
}
int in, out;

void enqueue(value) {
  sem_wait(&numspaces); // block when there's no space left!

  pthread_mutex_lock(&m);
  buffer[ (in++) & 0xf ] = value; // There must be space for this!
  pthread_mutex_unlock(&m);
  
  sem_post(&numitems);
}

task_t dequeue() {
  sem_wait(&numitems); //block when there's no items!

  pthread_mutex_lock(&m);
  result = buffer[ (out++) & 0xf ]; // There must be at least one item
  pthread_mutex_lock(&m);
  
  sem_post(&numspaces);
  return result; 
}
//Jordan Levy and Chris Moranda

typedef struct system_t {
    thread_t* array[3];
    int num_threads;
    volatile uint16_t system_time;
    int current_thread; //id
} system_t;

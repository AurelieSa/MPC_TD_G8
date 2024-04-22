
struct ga_s {
  unsigned int ga_size;
  unsigned int * ga_element;
};

int ga_set(struct ga_s* ga, unsigned int index, int val);

int ga_get(struct ga_s* ga, unsigned int index, unsigned int* val);

int ga_new(struct ga_s* ga); 

int ga_del(struct ga_s* ga); 

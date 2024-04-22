
typedef void (gfunc_t)(void*);

struct gfifo_node_s {
  void* val;
  struct gfifo_node_s* next;
};

struct gfifo_s {
  struct gfifo_node_s* head;
  struct gfifo_node_s* tail;
};

struct gfifo_s* gfifo_new(void);

int gfifo_is_empty(struct gfifo_s*);

int gfifo_size(struct gfifo_s*);

int gfifo_enqueue(struct gfifo_s*, void*);

int gfifo_dequeue(struct gfifo_s*, void**);

void* gfifo_head(const struct gfifo_s*);

void gfifo_del(struct gfifo_s*);

void gfifo_apply(struct gfifo_s*, gfunc_t);

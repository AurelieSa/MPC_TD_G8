
typedef int (func_t)(int);

struct ififo_node_s {
  int val;
  struct ififo_node_s* next;
};

struct ififo_s {
  struct ififo_node_s* head;
  struct ififo_node_s* tail;
};

struct ififo_s* ififo_new(void);

int ififo_is_empty(struct ififo_s*);

int ififo_enqueue(struct ififo_s*, int);

int ififo_dequeue(struct ififo_s*, int*);

int ififo_head(const struct ififo_s*);

void ififo_del(struct ififo_s*);

void ififo_apply(struct ififo_s*, func_t);

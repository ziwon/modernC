- Resizing an already extant array requires `realloc`, which only makes
  sense on blocks of memory intially allocated via `malloc`.
- Can't return an array from a function
- Wrap the memory managements for long live objects into new/copy/free
  functions
- Automatic memory (a few megabytes) is allocated on the stack of function frames,
  while large chunks of data should be allocated on the heap
- `void *` is the template as a returned pointer, returning struct
  without memory allocation can be done.

Production code tends to have few uses of `malloc`, typically wrapped in
`new/copy/free` functions


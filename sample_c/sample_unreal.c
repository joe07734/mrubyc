/*
 * This sample program executes ONE mruby/c program.
 * By this sample, you can know about mruby/c vm setup and execution.
 * The function mrubyc executes a bytecode pointed by mrbbuf.
 */

#include <stdio.h>
#include <stdlib.h>
#include "mrubyc.h"

#if !defined(MRBC_MEMORY_SIZE)
#define MRBC_MEMORY_SIZE (1024*40)
#endif
static uint8_t memory_pool[MRBC_MEMORY_SIZE];


int unreal_hal_write(int fd, const void *buf, int nbytes) {
  return (int)write(1, buf, nbytes);
}

int unreal_hal_flush(int fd) {
  return fsync(1);
}

void unreal_mrbc_out_of_memory(void) {
  fprintf(stderr, "unreal_mrbc_out_of_memory");
  exit(1);
}

uint8_t * load_mrb_file(const char *filename)
{
  FILE *fp = fopen(filename, "rb");

  if( fp == NULL ) {
    fprintf(stderr, "File not found (%s)\n", filename);
    return NULL;
  }

  // get filesize
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // allocate memory
  uint8_t *p = malloc(size);
  if( p != NULL ) {
    fread(p, sizeof(uint8_t), size, fp);
  } else {
    fprintf(stderr, "Memory allocate error.\n");
  }
  fclose(fp);

  return p;
}


int main(int argc, char *argv[])
{
  if( argc != 2 ) {
    printf("Usage: %s <xxxx.mrb>\n", argv[0]);
    return 1;
  }

  uint8_t *mrbbuf = load_mrb_file( argv[1] );
  if( mrbbuf == 0 ) return 1;

  int loop;
  for (loop = 0; loop < 10; ++loop) {

  /*
    start mruby/c with LOW LEVEL functions.
  */
  hal_init();
  mrbc_init_alloc(memory_pool, MRBC_MEMORY_SIZE);
  mrbc_init_global();
  mrbc_init_class();

  mrbc_vm *vm = mrbc_vm_open(NULL);
  if( vm == NULL ) {
    fprintf(stderr, "Error: Can't assign VM.\n");
    return 1;
  }

  if( mrbc_load_mrb(vm, mrbbuf) != 0 ) {
    mrbc_print_exception(&vm->exception);
    return 1;
  }

  mrbc_vm_begin( vm );
  int ret = mrbc_vm_run( vm );

  /*************/

  mrbc_class *componentClass = mrbc_get_class_by_name("TestRubyComponent");
  if (!componentClass) {
    fprintf(stderr, "Error: No componentClass\n");
    return 1;
  }
  mrbc_value componentInstance = mrbc_instance_new(vm, componentClass, 0);
  if (!componentInstance.instance) {
    fprintf(stderr, "Error: Failed to create componentInstance\n");
    return 1;
  }

  /*************/

  mrbc_method method;
  int method_sym_id;

  method_sym_id = mrbc_str_to_symid("beginPlay");
  if (method_sym_id == -1) {
    fprintf(stderr, "Error: No sym_id\n");
    return 1;
  }
  fprintf(stdout, "method_sym_id %d\n", method_sym_id);

  if (mrbc_find_method(&method, componentClass, method_sym_id) == 0) {
    fprintf(stderr, "Error: No method\n");
    return 1;
  }

  /*************/

  fprintf(stdout, "1\n");
  mrbc_vm_begin(vm);
  mrbc_vm_run_method(vm, &componentInstance, &method);
  fprintf(stdout, "2\n");

  mrbc_alloc_print_statistics();

  mrbc_vm_end( vm );
  mrbc_vm_close( vm );
  mrbc_cleanup_alloc();

  }  /* loop */

  /*
    Done
  */
  return 0;
}

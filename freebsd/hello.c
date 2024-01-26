#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/param.h>
#include <sys/types.h>

static int hello_load(module_t mod, int cmd, void *arg) {
  int err = 0;
  switch (cmd) {
  case MOD_LOAD:
    log(1, "Hello from FreeBSD module.");
    break;
  case MOD_UNLOAD:
    log(1, "Goodbye, Moonman!");
    break;
  default:
    err = EOPNOTSUPP;
    break;
  }
  return err;
}

static moduledata_t hello_mod = {"hello", hello_load, NULL};
DECLARE_MODULE(hello, hello_mod, SI_SUB_KLD, SI_ORDER_ANY);

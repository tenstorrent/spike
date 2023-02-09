// See LICENSE for license details.

#ifndef _RISCV_SIMIF_H
#define _RISCV_SIMIF_H

#include "decode.h"

// this is the interface to the simulator used by the processors and memory
class simif_t
{
public:
  // should return NULL for MMIO addresses
  virtual char* addr_to_mem(reg_t paddr) = 0;
  virtual bool reservable(reg_t paddr) { return addr_to_mem(paddr); }
  // used for MMIO addresses
  virtual bool mmio_fetch(reg_t paddr, size_t len, uint8_t* bytes) { return mmio_load(paddr, len, bytes); }
  virtual bool mmio_load(reg_t paddr, size_t len, uint8_t* bytes) = 0;
  virtual bool mmio_store(reg_t paddr, size_t len, const uint8_t* bytes) = 0;
  // Callback for processors to let the simulation know they were reset.
  virtual void proc_reset(unsigned id) = 0;

  virtual const char* get_symbol(uint64_t paddr) = 0;

  virtual bool is_tohost_nonzero() = 0;

  virtual ~simif_t() = default;

};

#endif

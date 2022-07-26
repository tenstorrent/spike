#ifndef _RISCV_MAX_INSTRS_EXCEPTION_H
#define _RISCV_MAX_INSTRS_EXCEPTION_H

class max_instrs_exception_t : public std::exception {
    public:
        const char* what()
        {
            return "Max instruction executed limit reached";
        }
};
      
#endif

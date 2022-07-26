#ifndef _RISCV_END_PC_EXCEPTION_H
#define _RISCV_END_PC_EXCEPTION_H

class end_pc_exception_t : public std::exception {
    public:
        const char* what()
        {
            return "End pc reached";
        }
};
      
#endif

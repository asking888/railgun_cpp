#ifndef CODE_OBJECT_HPP
#define CODE_OBJECT_HPP

#include <iostream>

#include "object/hiObject.hpp"
#include "util/arrayList.hpp"
#include "object/hiString.hpp"

class CodeObject : public HiObject {
friend class FunctionObject;

public:
    int _argcount;
    int _nlocals;
    int _stack_size;
    int _flag;

    HiString* _bytecodes;
    ArrayList<HiObject*>*  _names;
    ArrayList<HiObject*>*  _consts;
    ArrayList<HiObject*>*  _var_names;

    ArrayList<HiObject*>*  _free_vars;
    ArrayList<HiObject*>*  _cell_vars;

    HiString* _co_name;
    HiString* _file_name;

    int _lineno;
    char* _notable;

    CodeObject(int argcount, int nlocals, int stacksize, int flag, HiString* bytecodes,
                      ArrayList<HiObject*>* consts, ArrayList<HiObject*>* names, ArrayList<HiObject*>* varnames, 
                      ArrayList<HiObject*>* freevars, ArrayList<HiObject*>* cellvars,
                      HiString* file_name, HiString* co_name, int lineno, char* notable):
        _argcount(argcount),
        _nlocals(nlocals),
        _stack_size(stacksize),
        _flag(flag),
        _bytecodes(bytecodes),
        _names(names),
        _consts(consts),
        _var_names(varnames),
        _free_vars(freevars),
        _cell_vars(cellvars),
        _co_name(co_name),
        _file_name(file_name),
        _lineno(lineno),
        _notable(notable){
        }
};

#endif

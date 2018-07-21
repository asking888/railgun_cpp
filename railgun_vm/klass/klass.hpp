#ifndef _KLASS_HPP
#define _KLASS_HPP

#include <stdio.h>
#include "util/map.hpp"
#include "util/arrayList.hpp"

enum vm_type {
    TYPE_INT = 0,
    TYPE_STRING,
    TYPE_OBJECT,
    TYPE_TYPE,
};

class HiTypeObject;
class HiObject;
class HiString;
class OopClosure;

class Klass {
private:
    Klass*        _super;
    HiTypeObject* _type_object;
    NameTable     _klass_dict;
    HiString*     _name;

public:
    Klass();

    static HiObject* create_klass(HiObject* x, HiObject* supers, HiObject* name);

    void set_super(Klass* x)              { _super = x; }
    Klass* super()                        { return _super; }
    void set_type_object(HiTypeObject* x) { _type_object = x; }
    HiTypeObject* type_object()           { return _type_object; }

    void set_klass_dict(NameTable dict)   { _klass_dict = dict; }
    NameTable klass_dict()                { return _klass_dict; }

    void set_name(HiString* x)            { _name = x; }
    HiString* name()                      { return _name; }

    NameTable* klass_dict_address()       { return &_klass_dict; }

    virtual void print(HiObject* obj) {}

    virtual HiObject* greater  (HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* less     (HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* equal    (HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* not_equal(HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* ge       (HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* le       (HiObject* x, HiObject* y) { return 0; }

    virtual HiObject* add(HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* sub(HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* mul(HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* div(HiObject* x, HiObject* y) { return 0; }
    virtual HiObject* mod(HiObject* x, HiObject* y) { return 0; }

    virtual HiObject* getattr(HiObject* x, HiString* y) { return 0; }
    virtual HiObject* subscr (HiObject* x, HiObject* y) { return 0; }

    // alloacte instances
    virtual HiObject* allocate_instance() { return 0; }
    virtual HiObject* call(ArrayList<HiObject*>* args) { return 0; }

    // gc interfaces
    // this is for objects of this type.
    virtual void oops_do(OopClosure* closure, HiObject* obj);
    // for klass itself only.
    virtual void oops_do(OopClosure* closure);
    virtual size_t size();

    void* operator new(size_t size);
};

#endif

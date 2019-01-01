#pragma once

#include <stdlib.h>

//��ũ�η� Ȯ��Ǵ�, �迭 �������ø��Դϴ�.
//�����迭�� ���� ����Ŭ������ �����մϴ�.
#define decl_vector(declname,type) \
\
/*�迭 ����Ŭ���� ���漱��*/ \
struct declname; \
typedef struct declname declname; \
\
/*���� �ݺ��� ����Ŭ���� ���漱��*/ \
struct declname##_iterator; \
typedef struct declname##_iterator declname##_iterator; \
\
/*�ݺ��� ����Ŭ����.*/ \
struct declname##_iterator \
{ \
    type* ptr; \
\
    /*�ݺ��� �ϰų� ���ݺ��� ����*/ \
    void (*next)(declname##_iterator*); \
    void (*prev)(declname##_iterator*); \
\
    /*�ݺ��ڿ� ��� ���̳� �� �����͸� ������.*/ \
    type (*get)(const declname##_iterator*); \
    type* (*get_ptr)(declname##_iterator*); \
\
    /*�� �ݺ��ڸ� ��. ������ 1, �ٸ��� 0*/ \
    int (*equals)(const declname##_iterator*, const declname##_iterator*); \
}; \
/*���� �޼��� ����*/ \
void declname##_iterator_next(declname##_iterator*); \
void declname##_iterator_prev(declname##_iterator*); \
type declname##_iterator_get(const declname##_iterator*); \
type* declname##_iterator_get_ptr(declname##_iterator*); \
int declname##_iterator_equals(const declname##_iterator*, const declname##_iterator*); \
/*���� make �Լ� ����*/ \
declname##_iterator make_##declname##_iterator(type*); \
\
\
/*��üȭ�Ǵ� �迭 ����Ŭ����*/ \
struct declname \
{ \
    type* data; \
    size_t length; \
    size_t reserved_size; \
    \
    void (*push_back)(declname*, type); \
    void (*pop_back)(declname*); \
    \
    type (*back)(const declname*); \
    type* (*back_ptr)(declname*); \
    \
    void (*reserve)(declname*, size_t); \
    \
    void (*clear)(declname*)
    \
    /*���̸� ������*/ \
    size_t (*get_length)(const declname*); \
    \
    size_T (*get_capacity)(const declname*); \
    \
    int (*is_empty)(const declname*); \
    int (*is_not_empty)(const declname*); \
    \
    \
    /*���Ŀ�*/ \
    void (*sort)(declname*); \
    void (*sort_by)(declname*, int(*)(const type*, const type*)); \
    \
    declname (*clone)(const declname*); \
    \
    /*�ݺ��ڸ� ��ȯ*/ \
    declname##_iterator (*begin)(declname*); \
    declname##_iterator (*end)(declname*); \
    \
    /*�ش� ���̳� ���� �����ͷ�, �迭�� ä��*/ \
    void (*fill)(declname*, const type); \
    void (*fill_ptr)(declname*, const type*); \
    \
    /*����Ž�� �� ã�� ��ġ�� �ݺ��ڸ� ��ȯ*/ \
    declname##_iterator (*find)(const declname*, const type); \
    declname##_iterator (*find_by)(const declname*, int(*)(const type*)); \
    \
    /*����Ž�� �� ã�� ��ġ�� �ݺ��ڸ� ��ȯ*/ \
    declname##_iterator (*bfind)(const declname*, const type); \
    declname##_iterator (*bfind_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*����Ž�� �� �ش��ϴ� �ε����� ��ȯ*/ \
    size_t (*indexof)(const declname*, const type); \
    size_t (*indexof_by)(const declname*, int(*)(const type*)); \
    \
    /*����Ž�� �� �ش��ϴ� �ε����� ��ȯ*/ \
    size_t (*bindexof)(const declname*, const type); \
    size_t (*bindexof_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*����Ž������ ���� ���θ� Ȯ��*/ \
    int (*contains)(const declname*, const type); \
    int (*contains_by)(const declname*, int(*)(const type*)); \
    \
    /*����Ž������ ���� ���θ� Ȯ��*/ \
    int (*bcontains)(const declname*, const type); \
    int (*bcontains_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*�ݹ��Լ��� �޾Ƽ� ������� ������ ��*/ \
    void (*for_each)(const declname*, void(*)(const type)); \
    void (*for_each_ptr)(declname*, void(*)(type*)); \
}; \
/*���� �޼��� ����*/ \
size_t declname##_get_length(const declname*); \
void declname##_sort(declname*); \
void declname##_sort_by(declname*, int(*)(const type*, const type*)); \
declname declname##_clone(const declname*); \
declname##_iterator declname##_begin(declname*); \
declname##_iterator declname##_end(declname*); \
void declname##_fill(declname*, const type); \
void declname##_fill_ptr(declname*, const type*); \
declname##_iterator declname##_find(const declname*, const type); \
declname##_iterator declname##_find_by(const declname*, int(*)(const type*)); \
declname##_iterator declname##_bfind(const declname*, const type); \
declname##_iterator declname##_bfind_by(const declname*, const type*, int(*)(const type*, const type*)); \
size_t declname##_indexof(const declname*, const type); \
size_t declname##_indexof_by(const declname*, int(*)(const type*)); \
size_t declname##_bindexof(const declname*, const type); \
size_t declname##_bindexof_by(const declname*, const type*, int(*)(const type*, const type*)); \
int declname##_contains(const declname*, const type); \
int declname##_contains_by(const declname*, int(*)(const type*)); \
int declname##_bcontains(const declname*, const type); \
int declname##_bcontains_by(const declname*, const type*, int(*)(const type*, const type*)); \
void declname##_for_each(const declname*, void(*)(const type)); \
void declname##_for_each_ptr(declname*, void(*)(type*)); \
/*���� �Լ�*/ \
declname make_##declname (void); \
declname make_##declname##_with (size_t); \
\
\
/*�迭 �޼��� ����.*/ \
size_t declname##_get_length(const declname* self) \
{ \
    return self->length; \
} \
\
int declname##_comparer(const void* lhs, const void* rhs) \
{ \
    return *(type*)lhs - *(type*)rhs; \
} \
\
void declname##_sort(declname* self) \
{ \
    qsort(self->data, length, sizeof(type), declname##_comparer); \
} \
\
void declname##_sort_by(declname* self, int(*comp)(const type*, const type*)) \
{ \
     qsort(self->data, self->length, sizeof(type), comp); \
} \
\
declname declname##_clone(const declname* self) \
{ \
    declname temp = make_##declname(); \
    for(int i=0;i<self->length;++i) \
        temp.data[i] = self->data[i]; \
    return temp; \
} \
\
declname##_iterator declname##_begin(declname* self) \
{ \
    declname##_iterator it = \
    make_##declname##_iterator(self->data); \
    return it; \
} \
\
declname##_iterator declname##_end(declname* self) \
{ \
    declname##_iterator it = \
    make_##declname##_iterator(self->data + self->length); \
    return it; \
} \
\
void declname##_fill(declname* self, const type value) \
{ \
    for(int i = 0; i<self->length; ++i) \
        self->data[i] = value; \
} \
\
void declname##_fill_ptr(declname* self, const type* value) \
{ \
    for(int i = 0; i<self->length; ++i) \
        self->data[i] = *value; \
} \
\
declname##_iterator declname##_find(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i)\
        if(self->data[i] == key) \
            return make_##declname##_iterator((type*)&(self->data[i])); \
    \
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_find_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i)\
        if(comp(&self->data[i])) \
            return make_##declname##_iterator((type*)&(self->data[i])); \
    \
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_bfind(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return make_##declname##_iterator(p); \
    return self->end((declname*)&self); \
} \
\
int declname##_bsearch(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int head = 0; \
    int tail = self->length-1; \
    int middle; \
    \
    while(1) \
    { \
        int comp_head = comp(key, &self->data[head]); \
        int comp_tail = comp(key, &self->data[tail]); \
        if(comp_head<0 || comp_tail>0) \
            return self->length; \
        if(comp_head==0) \
            return head; \
        if(comp_tail==0) \
            return tail; \
        \
        middle = (tail - head)/2; \
        int comp_mid = comp(key, &self->data[middle]); \
        if(comp_mid == 0) \
            return middle; \
        else if(0<comp_mid) /*key�� �߰�ġ���� ŭ*/ \
            --tail, head = middle; \
        else /*key�� �߰�ġ���� ����*/ \
            ++head, tail = middle; \
    } \
} \
\
declname##_iterator declname##_bfind_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return make_##declname##_iterator((type*)&self->data[index]); \
    return self->end((declname*)&self); \
} \
\
size_t declname##_indexof(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(self->data[i] == key) \
            return i; \
    return self->length; \
} \
\
size_t declname##_indexof_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(comp(&self->data[i])) \
            return i; \
    return self->length; \
} \
\
size_t declname##_bindexof(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return p - self->data; \
    return self->length; \
} \
\
size_t declname##_bindexof_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return index; \
    return self->length; \
} \
\
int declname##_contains(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(self->data[i] == key) \
        return 1; \
    return 0; \
} \
\
int declname##_contains_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(comp(&self->data[i])) \
            return 1; \
    return 0; \
} \
\
int declname##_bcontains(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return 1; \
    return 0; \
} \
\
int declname##_bcontains_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return 1; \
    return 0; \
} \
\
void declname##_for_each(const declname* self, void(*f)(const type)) \
{ \
    for(int i =0; i<self->length; ++i) \
        f(self->data[i]); \
} \
\
void declname##_for_each_ptr(declname* self, void(*f)(type*)) \
{ \
    for(int i =0; i<self->length; ++i) \
        f(&self->data[i]); \
} \
\
declname make_##declname (void) \
{ \
    declname temp = \
    { \
        .data = NULL, \
        .length = 0, \
        .reserved_length = 0, \
        .get_length= declname##_get_length, \
        .sort= declname##_sort, \
        .sort_by= declname##_sort_by, \
        .clone= declname##_clone, \
        .begin= declname##_begin, \
        .end= declname##_end, \
        .fill= declname##_fill, \
        .fill_ptr= declname##_fill_ptr, \
        .find= declname##_find, \
        .find_by= declname##_find_by, \
        .bfind= declname##_bfind, \
        .bfind_by= declname##_bfind_by, \
        .indexof= declname##_indexof, \
        .indexof_by= declname##_indexof_by, \
        .bindexof= declname##_bindexof, \
        .bindexof_by= declname##_bindexof_by, \
        .contains= declname##_contains, \
        .contains_by= declname##_contains_by, \
        .bcontains= declname##_bcontains, \
        .bcontains_by= declname##_bcontains_by, \
        .for_each= declname##_for_each, \
        .for_each_ptr= declname##_for_each_ptr \
    }; \
    return temp; \
} \
\
declname make_##declname##_with (size_t len) \
{ \
    declname temp = \
    { \
        .data = malloc(sizeof(type)*len)
        .get_length= declname##_get_length, \
        .sort= declname##_sort, \
        .sort_by= declname##_sort_by, \
        .clone= declname##_clone, \
        .begin= declname##_begin, \
        .end= declname##_end, \
        .fill= declname##_fill, \
        .fill_ptr= declname##_fill_ptr, \
        .find= declname##_find, \
        .find_by= declname##_find_by, \
        .bfind= declname##_bfind, \
        .bfind_by= declname##_bfind_by, \
        .indexof= declname##_indexof, \
        .indexof_by= declname##_indexof_by, \
        .bindexof= declname##_bindexof, \
        .bindexof_by= declname##_bindexof_by, \
        .contains= declname##_contains, \
        .contains_by= declname##_contains_by, \
        .bcontains= declname##_bcontains, \
        .bcontains_by= declname##_bcontains_by, \
        .for_each= declname##_for_each, \
        .for_each_ptr= declname##_for_each_ptr \
    }; \
} \
\
/*�ݺ��� �޼��� ����*/ \
void declname##_iterator_next(declname##_iterator* self) \
{ \
    ++(self->ptr); \
} \
\
void declname##_iterator_prev(declname##_iterator* self) \
{ \
    --(self->ptr); \
} \
\
type declname##_iterator_get(const declname##_iterator* self) \
{ \
    return *(self->ptr); \
} \
\
type* declname##_iterator_get_ptr(declname##_iterator* self) \
{ \
    return self->ptr; \
} \
\
int declname##_iterator_equals(const declname##_iterator* self, const declname##_iterator* other) \
{ \
    return self->ptr == other->ptr; \
} \
\
declname##_iterator make_##declname##_iterator(type* p) \
{ \
    declname##_iterator it = \
    { \
        p, \
        declname##_iterator_next, \
        declname##_iterator_prev, \
        declname##_iterator_get, \
        declname##_iterator_get_ptr, \
        declname##_iterator_equals \
    }; \
    return it; \
} \

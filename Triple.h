#ifndef TRIPLE_H
#define TRIPLE_H


template <typename F, typename S, typename T> class Triple {
public:
    F first;
    S second;
    T third;
    Triple () {}
    Triple (F one, S two, T three) : first(one), second(two), third(three) {}
};


#endif // TRIPLE_H
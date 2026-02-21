#ifndef STATEPAIR
#define STATEPAIR

template<typename T1, typename T2>
class StatePair {

// TODO: Define constructors
   StatePair();
   StatePair(T1 userKey, T2 userValue);
   ~StatePair();
   
// TODO: Define mutators, and accessors for StatePair
   void SetKey(T1 userKey);
   void SetValue(T2 userValue);
public:
   T1 GetKey();
   T2 GetValue();
	
// TODO: Define PrintInfo() method
    void PrintInfo();
};

#endif